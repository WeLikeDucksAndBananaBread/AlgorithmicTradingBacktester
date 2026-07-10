#ifndef STRATEGY_BASE_H
#define STRATEGY_BASE_H

#include <QObject>

class StrategyBase : public QObject
{
    Q_OBJECT
public:
    explicit StrategyBase(QObject *parent = nullptr);
    ~StrategyBase() override = default;

    // QObject is non-copyable, so explicitly delete copy operations
    StrategyBase(const StrategyBase&) = delete;
    auto operator=(const StrategyBase&) -> StrategyBase& = delete;
    StrategyBase(StrategyBase&&) = delete;
    auto operator=(StrategyBase&&) -> StrategyBase& = delete;

    virtual void onTick() = 0;
    virtual void onBar() = 0;

signals:

};

#endif // STRATEGY_BASE_H
