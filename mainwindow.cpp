#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSplitter>
#include <QListView>
#include <QTreeView>
#include <QTextEdit>
#include <QFileSystemModel>
#include <QItemSelectionModel>
#include <QVBoxLayout>
#include <QTableView>
#include <QHeaderView>
#include <QStatusBar>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileModel = new ByFileType_CalculationStrategy;
    folderModel = new ByFolder_CalculationStrategy;
    strat = folderModel;
    currentDirectory = QDir::homePath();
    directoryModel =  new QFileSystemModel(this);
    directoryModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);

    currentDirectory = QDir::homePath();

    Model_ = new Model(this, strat->CalculationMethod(currentDirectory));
    ptrModel = Model_;

    tableView = new QTableView(this);
    tableView->setModel(Model_);

    view=tableView;

    BarGraph = new BarGraphAdapter(this,strat->CalculationMethod(currentDirectory));
    PieChart = new PieChartAdapter(this,strat->CalculationMethod(currentDirectory));
    BView = new QChartView(BarGraph->fChart());
    PView = new QChartView(PieChart->fChart());

    ui->horizontalLayout_2->addWidget(tableView);
    ui->horizontalLayout_2->addWidget(BView,2);
    ui->horizontalLayout_2->addWidget(PView,2);
    BView->hide();
    PView->hide();


    directoryModel = new QFileSystemModel(this);
    directoryModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    directoryModel->setRootPath(QDir::rootPath());

    ui->treeView->setModel(directoryModel);

    QItemSelectionModel *selectionModel = ui->treeView->selectionModel();

    connect(ui->treeView,SIGNAL(expanded(const QModelIndex &)),this,SLOT(ResizeColBasedOnData()));
    connect(ui->treeView,SIGNAL(collapsed(const QModelIndex &)),this,SLOT(ResizeColBasedOnData()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(sortTypeChange(int)));
    connect(ui->comboBox_2,SIGNAL(currentIndexChanged(int)),this,SLOT(displayTypeChange(int)));




    connect(selectionModel, SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
               this, SLOT(FolderReSelection(const QItemSelection &)));




}

void MainWindow::FolderReSelection(const QItemSelection &selected)
{

    QModelIndexList is =  selected.indexes();
    if (is.count() >= 1)
    {
        QModelIndex ix =  is.constFirst();
        currentDirectory = directoryModel->filePath(ix);
    }
    ptrModel->setModel(strat->CalculationMethod(currentDirectory));
}



void MainWindow::ResizeColBasedOnData()
{
    ui->treeView->resizeColumnToContents(0);
}

void MainWindow::sortTypeChange(int type)
{
    if(type == 0)
    {
       strat = folderModel;
    }
    else
        strat = fileModel;

    Model_->setModel(strat->CalculationMethod(currentDirectory));
}


void MainWindow::displayTypeChange(int display_id)
{
    view->hide();
    switch (display_id)
    {
    case 0:
        view = tableView;
        ptrModel = Model_;
        break;
    case 1:

        view = BView;
        ptrModel = BarGraph;
        break;
    case 2:
        view = PView;
        ptrModel = PieChart;
        break;
    }
    ptrModel->setModel(strat->CalculationMethod(currentDirectory));
    view->show();
}



MainWindow::~MainWindow()
{
    delete ui;
}




