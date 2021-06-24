#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H

#include <QString>
#include <QDir>
#include <QList>
#include <iostream>
#include <initdata.h>

class CalculationStrategy
{
public:
    virtual QList<InitData> CalculationMethod(const QString&) = 0;
    static double FullDirSize(QString Dir);
};

#endif // CALCULATIONSTRATEGY_H
