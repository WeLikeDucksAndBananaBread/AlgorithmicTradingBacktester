#ifndef BACKTEST_ENGINE_H
#define BACKTEST_ENGINE_H

#include <QObject>

class BacktestEngine : public QObject
{
    Q_OBJECT
public:
    explicit BacktestEngine(QObject *parent = nullptr);

signals:

};

#endif // BACKTEST_ENGINE_H
