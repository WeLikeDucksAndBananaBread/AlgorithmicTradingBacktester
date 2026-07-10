#ifndef SIMULATION_LOOP_H
#define SIMULATION_LOOP_H

#include <QObject>

class SimulationLoop : public QObject
{
    Q_OBJECT
public:
    explicit SimulationLoop(QObject *parent = nullptr);

signals:

};

#endif // SIMULATION_LOOP_H
