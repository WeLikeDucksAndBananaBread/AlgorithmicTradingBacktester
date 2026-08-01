# Threads and global signal-slots
This document provides **concurrent implementation** for multithreading and global signal-slots plan,shows how to implement it with simple examples.

## 1.Qt Concurrent Setup
### 1.1 First,CMake must be configured:
```cmake
find_package(Qt6 6.X REQUIRED COMPONENTS Core Widgets Concurrent)

target_link_libraries(Project_Name
    PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Concurrent
)
```
### 1.2 Include QtConccurent,QFuture and QThread in the main class
```cpp
#include <QtConcurrent>
#include <QFuture>
#include <QThread>
#include <QFutureWatcher>
```
1.3 Overview of QtConccurent
-The system does not manually create QThread,instead it uses Qt's Global Thread Pool to efficiently reuse threads.
-All long-running or blocking method and function are offloaded to QtConccurent threas,provide accessible GUI experience.
-Communication between threads is thread-safe,utilizing pass-by-value and QFutureWatcher signals.

## 2.Global signal-slots with QFutureWatcher
### 2.1 Defining a composition for separate of the project.Create a owner object for each part.
```cpp
#ifndef DATA_H
#define DATA_H

#include <QObject>

class Data : public QObject
{
    ...
};
#endif // DATA_H
```
```cpp
#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>

class Engine : public QObject
{
    ...
};
#endif // ENGINE_H
```
Composing owner objects into the main class.("Main class can be the MainWindow or create another main class and use it to aggregate the owner objects")
```cpp
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data.h"
#include "engine.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    //Allocate the host objects on the heap
    Data *d; 
    Engine *e;
    ...
};
#endif // MAINWINDOW_H
```
### 2.2 Task and roles of owner objects
Owner object's slots connects the UI and other owner object's signals (not explicit) in the main class,wich can be in the main class's constructor or define a method for this.
```cpp
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    d = new Data();
    e = new Engine();
    QObject::connect(d,&Data::finish,this,&MainWindow::finish_data); //finish is a signal and finish_data is a slot
    ...
}
```
Owner object's slots call class methods and can emit signal when finished.It can signal the UI to refesh or owner objects(not explicit).
(This exmaple defined in the MainWindow,tha's why the _this_ keyword)
```cpp
QObject::connect(d,&Data::finish,this,&MainWindow::finish_data);
```
### 2.3 Connection type
Connection type most of ```Qt::AutoConnection``` (or explicit ```Qt::QueuedConnection```)
```cpp
QObject::connect(d,&Data::finish,this,&MainWindow::finish_data,Qt::QueuedConnection); //Automatically Qt::AutoConnection 
```
### 2.4 Conccurent with QFuturewatcher
That's why there isn't direct connection between two owner objects.Because we want to run difficult and timeconsuming taks on background thread.(it could be done using objects moved to athor thread).From the examples above (MainWindow::finish_data)
```cpp
void MainWindow::finish_data(){
    auto watcher = new QFutureWatcher<void>(this);
    connect(watcher, &QFutureWatcher<void>::finished, this, [this, watcher]() {
        ui->label->setText("Finish the background work"); //if (QFuture) future finish
        watcher->deleteLater();
    });
    QFuture<void> future = QtConcurrent::run([this]() {
        e->doHeavyComputation(d);
    });
    watcher->setFuture(future); //Watch when finish the future
}
```
### 2.5 Thread safety
QtConcurrent and QFutureWtacher's greatest advantage is thread safety.All background functions **require a return statement** and **pass everything as a parameter**.
### 2.6 Managing Asynchronous Tasks with QFutureWatcher
`QFutureWatcher` provides built-in control slots and signals to monitor and manage asynchronous operations seamlessly from the GUI thread.
#### Key Public Slots for Task Control:
**`QFutureWatcher::setFuture()`** : Associates a `QFuture` task with the watcher to start monitoring its execution lifecycle.
**`QFutureWatcher::pause()`** : Pauses the background task (e.g., suspends batch processing or data calculations).
**`QFutureWatcher::resume()`** : Resumes the previously paused background task.
**`QFutureWatcher::cancel()`** : Cancels the execution of the task (e.g., when the user switches to a different dataset or aborts the operation).
## Performance and resource limits
Small tasks do not require a new thread.Use a macimum of 3 threads,for Engine,for Data and UI.
What counts as a small task depends on input data and time complexity ($\mathcal{O}(\log n)$)
## Testing
- - -
## Move Object to other thread and ThreadPool
Moving an enite object to a thread,so all its methods calls automatically run on those threads.This is where the use QMutex and QMutexLocker and QRunnable ,if you call the method from another thread at the same time,it will be crash.

