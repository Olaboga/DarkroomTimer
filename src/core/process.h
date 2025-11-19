#ifndef PROCESS_H
#define PROCESS_H

#include "bath.h"
#include <QString>
#include <QVector>

class Process : public QObject
{
    Q_OBJECT

public:
    Process();
    void AddBath(Bath* bath);

public slots:
    void SetName(const QString& name);

private:
    QString m_name;
    QVector<Bath*> m_baths;
};

#endif // PROCESS_H
