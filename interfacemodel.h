#ifndef INTERFACEMODEL_H
#define INTERFACEMODEL_H

#include <QList>
#include <QChart>
#include <initdata.h>

using namespace QtCharts;


class InterfaceModel

{
public:
    InterfaceModel();
    virtual void setModel(QList<InitData> model) = 0;

};

#endif // INTERFACEMODE_H
