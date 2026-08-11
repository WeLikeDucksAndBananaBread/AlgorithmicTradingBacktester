# Plan to load and save data
This document explain how and where to back up your data ,for reading only **JSON** and **CSV** based files.
## File reading
### Type
File reading runs on background thread.
File reading provides that the correct data is read,so can filter by **Date**,**Open**,**High**,**Low**,**Close** and **Volume**.
It saves the data in a `QVector<CandleStick>` data structure.
```cpp
struct CandleStick {
  qint64 date; 
  double open;
  double high;
  double low;
  double close;
  double volume;
};
```
- **Date**: If necessary,the `QDateTime` must be converted into `qin64`.For example:
```cpp
    #include <QDateTime>
    ...
    QDateTime startTime(QDate(2026, 7, 27), QTime(0, 0));
    qint64 startTimeMs = start.toMSecsSinceEpoch();
```
- **Open,High,Low,Close** : Read it as a double
- **Volume** : If there are more than one such column,then read first column.
### Error Handling
If the file is incomplete format or type is invalid.**Emit signal** to ui,so that ui can display an **error message on the main thread**.Errors handled separately with __unique descriptions__ to help with this the user.
### Thread safetly
The data is encapsulated within the **Data Owner Class**.When file reading is complete,then **emit signal** to __main class__.Signal give `QVector<CandleStick>` to main thread.
```cpp
signals:
    void dataLoaded(const QVector<CandleStick>& data);
```
Then main thread triggers the Engine using `QtConccurent:run`.
### Properties
- The vector must be in ascending order of time.(The earliest time is at index 0)
- Important is for ui,so separate storage of **start and end time** as a **public property**.
- Assigning a value of 0 to __numerically small numbers__

