#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTreeView>
#include <QFileSystemModel>
#include <QTableView>
#include <QtCharts/QChart>

#include <calculationstrategy.h>
#include "initdata.h"
#include "model.h"
#include "byfiletype_calculationstrategy.h"
#include "byfolder_calculationstrategy.h"
#include "charts.h"

class QTableView;
class QItemSelection;
class QAbstractItemView;

#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QAbstractBarSeries>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLegend>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtCore/QTime>
#include <QtCharts/QBarCategoryAxis>



QT_BEGIN_NAMESPACE
class QComboBox;
class QCheckBox;
QT_END_NAMESPACE

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE
QT_CHARTS_USE_NAMESPACE


namespace Ui { class MainWindow; }
class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void FolderReSelection(const QItemSelection &selected);
    void ResizeColBasedOnData();
    void sortTypeChange(int type);
    void displayTypeChange(int display_id);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QWidget* view;


    QTableView *tableView;
    Model* Model_;
    Model*ptrModel;
    ByFolder_CalculationStrategy* folderModel;
    ByFileType_CalculationStrategy* fileModel;
    CalculationStrategy *strat;
    QFileSystemModel *directoryModel;
    QString currentDirectory;
    QFileSystemModel *dirModel;

    BarGraphAdapter* BarGraph;
    PieChartAdapter* PieChart;
    QChartView *BView;
    QChartView *PView;
};



#endif // MAINWINDOW_H
