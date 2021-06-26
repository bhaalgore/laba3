#include "charts.h"

void Charts::setModel(QList<InitData> Model)
{
    auto series = ListToSeries(Model);
    updateChart(series);
}
 void Charts::updateChart(QAbstractSeries* Series)
 {
     chart->removeAllSeries();
     chart->addSeries(Series);
 }

 PieChartAdapter::PieChartAdapter(QWidget *parent,const QList<InitData>& data)
 {
     Q_UNUSED(parent);
     Q_UNUSED(data);
     chart = new QChart();
 }

 void Charts::descriptions()
 {
     chart->legend()->setAlignment(Qt::AlignLeft);
 }

 QAbstractSeries* PieChartAdapter::ListToSeries(QList<InitData> model)
 {
     const auto Series = new QPieSeries;
     for (const auto& i : model)
     {
         const auto label = i.name_ + " - " + QString::number(i.percent_* 100, 'f', 2) + "%";
         const auto value = i.percent_* 100;
         const auto set = new QBarSet(label);
         const auto slice = new QPieSlice(label, value);
         Series->append(slice);
         set->append(i.percent_* 100);
     }
     return Series;
 }


 QChart * PieChartAdapter::fChart()
 {
     return chart;
 }


 /*void PieChartAdapter::descriptions()
 {
     chart->legend()->setAlignment(Qt::AlignLeft);
 }*/

 BarGraphAdapter::BarGraphAdapter(QWidget *parent,const QList<InitData>& data)
 {
     Q_UNUSED(parent);
     Q_UNUSED(data);
     chart = new QChart;

 }

 QAbstractSeries* BarGraphAdapter::ListToSeries(QList<InitData> model)
 {
     const auto Series = new QBarSeries;
     for (const auto& i : model)
     {
         const auto label = i.name_+" - "+QString::number(i.percent_* 100, 'f', 2)+"%";
         const auto set = new QBarSet(label);
         set->append(i.percent_* 100);
         Series->append(set);
     }
     return Series;
 }


 QChart * BarGraphAdapter::fChart()
 {
     return chart;
 }

 /*void BarGraphAdapter::descriptions()
 {
     chart->legend()->setAlignment(Qt::AlignRight);
 }*/
