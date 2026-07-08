#ifndef CUSTOM_WIDGETS_H
#define CUSTOM_WIDGETS_H

#include <QWidget>

// It's better to have separate files for each custom widget,
// but for now, we can have a placeholder.

class SomeCustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SomeCustomWidget(QWidget *parent = nullptr);
};


#endif // CUSTOM_WIDGETS_H
