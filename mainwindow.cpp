#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    folderModel = new ByFolder_CalculationStrategy;
    strat = folderModel;
    currentDirectory = QDir::homePath();
    directoryModel =  new QFileSystemModel(this);
    directoryModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);

    currentDirectory = QDir::homePath();

    Model_ = new Model(this, strat->CalculationMethod(currentDirectory));

    tableView = new QTableView(this);
    tableView->setModel(Model_);

    view = tableView;

    ui->horizontalLayout_2->addWidget(tableView,2);

}


MainWindow::~MainWindow()
{
    delete ui;
}




