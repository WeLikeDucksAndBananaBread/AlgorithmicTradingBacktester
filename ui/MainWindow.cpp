#include "ui/MainWindow.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "core/AppInfo.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle(app::windowTitle());

    auto *centralWidget = new QWidget(this);
    auto *layout = new QVBoxLayout(centralWidget);

    auto *button = new QPushButton(tr("Hello, world!"), centralWidget);
    button->setMinimumSize(200, 100);

    layout->addWidget(button);
    layout->addStretch();

    setCentralWidget(centralWidget);
}

