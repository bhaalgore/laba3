#ifndef BYFILETYPE_CALCULATIONSTRATEGY_H
#define BYFILETYPE_CALCULATIONSTRATEGY_H


#include "calculationstrategy.h"

class ByFileType_CalculationStrategy : public CalculationStrategy
{
public:
    QList<InitData> CalculationMethod(const QString& path);
};

#endif // BYFILETYPE_CALCULATIONSTRATEGY_H
