#ifndef CONDITION_BASE_H
#define CONDITION_BASE_H

#include <QObject>

class ConditionBase : public QObject
{
    Q_OBJECT
public:
    explicit ConditionBase(QObject *parent = nullptr);
    ~ConditionBase() override = default;

    // QObject is non-copyable, so explicitly delete copy operations
    ConditionBase(const ConditionBase&) = delete;
    auto operator=(const ConditionBase&) -> ConditionBase& = delete;
    ConditionBase(ConditionBase&&) = delete;
    auto operator=(ConditionBase&&) -> ConditionBase& = delete;

    virtual auto check() -> bool = 0;

signals:

};

#endif // CONDITION_BASE_H
