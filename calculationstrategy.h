#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H

#include <QString>
#include <QDir>
#include <QList>
#include <iostream>


class CalculationStrategy
{
public:
    virtual QList<std::pair<QString,double>> CalculationMethod(const QString&) = 0;
    static double FullDirSize(QString Dir);
};

#endif // CALCULATIONSTRATEGY_H
