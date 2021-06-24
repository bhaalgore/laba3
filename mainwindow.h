#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTreeView>
#include <QFileSystemModel>
#include <QTableView>


#include <calculationstrategy.h>
#include "initdata.h"
#include "model.h"
#include "byfiletype_calculationstrategy.h"
#include "byfolder_calculationstrategy.h"

class QTableView;
class QItemSelection;
class QAbstractItemView;


//class ByFileType_CalculationStrategy;
//class ByFolder_CalculationStrategy;

namespace Ui { class MainWindow; }
class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QWidget* view;

    Model* Model_;
    ByFolder_CalculationStrategy* folderModel;
    ByFileType_CalculationStrategy* fileModel;
    CalculationStrategy *strat;
    QFileSystemModel *directoryModel;
    QTableView *tableView;
    QString currentDirectory;
};

#endif // MAINWINDOW_H
