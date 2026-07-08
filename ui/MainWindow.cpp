#include "ui/MainWindow.h"

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "core/AppInfo.h"

namespace {
constexpr int kButtonMinWidth = 200;
constexpr int kButtonMinHeight = 100;
} // namespace

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle(app::windowTitle());

    auto *centralWidget = new QWidget(this); // NOLINT(cppcoreguidelines-owning-memory)
    auto *layout = new QVBoxLayout(centralWidget); // NOLINT(cppcoreguidelines-owning-memory)

    auto *button = new QPushButton(tr("Hello, world!"), centralWidget);
    button->setMinimumSize(kButtonMinWidth, kButtonMinHeight);

    layout->addWidget(button);
    layout->addStretch();

    setCentralWidget(centralWidget);
}

