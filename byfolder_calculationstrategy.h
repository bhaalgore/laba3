#ifndef BYFOLDER_CALCULATIONSTRATEGY_H
#define BYFOLDER_CALCULATIONSTRATEGY_H

#include "calculationstrategy.h"

class ByFolder_CalculationStrategy: public CalculationStrategy
{
public:
    QList<InitData> CalculationMethod(const QString& path);
};

#endif // BYFOLDER_CALCULATIONSTRATEGY_H
