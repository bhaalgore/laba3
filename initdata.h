#ifndef INITDATA_H
#define INITDATA_H


#include <QString>

class InitData
{
public:
    InitData(QString name, double sizePercent, double size);

    QString name_;
    double size_;
    double percent_;
};


#endif // INOTDATA_H
