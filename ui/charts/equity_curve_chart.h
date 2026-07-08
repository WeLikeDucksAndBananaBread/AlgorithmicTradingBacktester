#ifndef EQUITY_CURVE_CHART_H
#define EQUITY_CURVE_CHART_H

#include <QWidget>

class QCustomPlot;

class EquityCurveChart : public QWidget
{
    Q_OBJECT
public:
    explicit EquityCurveChart(QWidget *parent = nullptr);

private:
    QCustomPlot* m_customPlot;

};

#endif // EQUITY_CURVE_CHART_H
