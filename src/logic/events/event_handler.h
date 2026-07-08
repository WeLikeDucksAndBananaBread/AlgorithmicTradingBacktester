#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <QObject>

class EventHandler : public QObject
{
    Q_OBJECT
public:
    explicit EventHandler(QObject *parent = nullptr);

signals:

};

#endif // EVENT_HANDLER_H
