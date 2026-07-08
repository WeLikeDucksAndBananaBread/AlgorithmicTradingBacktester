#ifndef EMA_H
#define EMA_H

#include <QObject>

class EMA : public QObject
{
    Q_OBJECT
public:
    explicit EMA(QObject *parent = nullptr);

signals:

};

#endif // EMA_H
