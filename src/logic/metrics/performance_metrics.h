#ifndef PERFORMANCE_METRICS_H
#define PERFORMANCE_METRICS_H

#include <QObject>

class PerformanceMetrics : public QObject
{
    Q_OBJECT
public:
    explicit PerformanceMetrics(QObject *parent = nullptr);

signals:

};

#endif // PERFORMANCE_METRICS_H
