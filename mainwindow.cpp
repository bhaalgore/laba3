#include "mainwindow.h"
#include "ui_mainwindow.h"


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

    tableView = new QTableView(this);
    tableView->setModel(Model_);


    ui->horizontalLayout_2->addWidget(tableView);
    directoryModel = new QFileSystemModel(this);
    directoryModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    directoryModel->setRootPath(QDir::rootPath());

    ui->treeView->setModel(directoryModel);

    QItemSelectionModel *selectionModel = ui->treeView->selectionModel();

    connect(ui->treeView,SIGNAL(expanded(const QModelIndex &)),this,SLOT(ResizeColBasedOnData()));
    connect(ui->treeView,SIGNAL(collapsed(const QModelIndex &)),this,SLOT(ResizeColBasedOnData()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(sortTypeChange(int)));
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
    Model_->setModel(strat->CalculationMethod(currentDirectory));
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

MainWindow::~MainWindow()
{
    delete ui;
}




