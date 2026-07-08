#ifndef CONDITION_BASE_H
#define CONDITION_BASE_H

#include <QObject>

class ConditionBase : public QObject
{
    Q_OBJECT
public:
    explicit ConditionBase(QObject *parent = nullptr);
    virtual ~ConditionBase() = default;

    virtual bool check() = 0;

signals:

};

#endif // CONDITION_BASE_H
