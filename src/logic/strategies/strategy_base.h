#ifndef STRATEGY_BASE_H
#define STRATEGY_BASE_H

#include <QObject>

class StrategyBase : public QObject
{
    Q_OBJECT
public:
    explicit StrategyBase(QObject *parent = nullptr);
    virtual ~StrategyBase() = default;

    virtual void onTick() = 0;
    virtual void onBar() = 0;

signals:

};

#endif // STRATEGY_BASE_H
