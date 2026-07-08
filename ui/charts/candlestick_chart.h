#ifndef CANDLESTICK_CHART_H
#define CANDLESTICK_CHART_H

#include <QWidget>

// Forward declaration of QCustomPlot.
// This assumes qcustomplot.h will be included in the .cpp file
// and that the project is configured to find it.
class QCustomPlot;

class CandlestickChart : public QWidget
{
    Q_OBJECT
public:
    explicit CandlestickChart(QWidget *parent = nullptr);

private:
    QCustomPlot* m_customPlot = nullptr;
};

#endif // CANDLESTICK_CHART_H
