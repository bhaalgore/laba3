#ifndef CHARTS_H
#define CHARTS_H

#include "initdata.h"
#include "model.h"
#include <QtCharts>


using namespace QtCharts;

class Charts:public InterfaceModel
{
public:
    void setModel(QList<InitData> model);
    void updateChart(QAbstractSeries* series);
    virtual QAbstractSeries* ListToSeries(QList<InitData> model) = 0;
    virtual void descriptions();
    //virtual void descriptions() = 0;

protected:
    QChart* chart;
};

class PieChartAdapter:public Charts
{
public:
   PieChartAdapter(QWidget *parent, const QList<InitData>& data);
    ~PieChartAdapter() = default;
   QAbstractSeries* ListToSeries(QList<InitData> model);
   QChart * fChart();
   //void descriptions();
};

class BarGraphAdapter:public Charts
{
public:
    BarGraphAdapter(QWidget *parent, const QList<InitData>& data);
    ~BarGraphAdapter() = default;
    QAbstractSeries* ListToSeries(QList<InitData> model);
    QChart * fChart();
    //void descriptions();

};

#endif
