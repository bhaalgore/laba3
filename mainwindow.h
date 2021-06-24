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



namespace Ui { class MainWindow; }
class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void FolderReSelection(const QItemSelection &selected);
    void ResizeColBasedOnData();
    void sortTypeChange(int type);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QWidget* view;

    QTableView *tableView;
    Model* Model_;
    ByFolder_CalculationStrategy* folderModel;
    ByFileType_CalculationStrategy* fileModel;
    CalculationStrategy *strat;
    QFileSystemModel *directoryModel;
    QString currentDirectory;
};



#endif // MAINWINDOW_H
