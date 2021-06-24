#include <iostream>
#include <QApplication>

#include "mainwindow.h"
#include "calculationstrategy.h"
#include "byfolder_calculationstrategy.h"
#include "byfiletype_calculationstrategy.h"


using namespace std;

/*void PrintInfo(QString Dir, CalculationStrategy* strat)
{
   QList<pair<QString,double>> FilesList = strat->CalculationMethod(Dir);
   double Size = CalculationStrategy::FullDirSize(Dir);

   double x=0;
   if(FilesList.isEmpty())
       cout << "Directory is empty.";
   else{
       for(auto& currentFile : FilesList)
       {
           if(Size!=0)
           {
             x = (currentFile.second)*100/Size + x;
           }
           if (currentFile.second >= 0.01){
               cout << currentFile.first.toStdString() << " - " << (int)((currentFile.second)*100/Size*100)/100. << "%" << endl;
           }
           else{
                   if(currentFile.second){
                   cout << currentFile.first.toStdString() << " - " << "<0.01%" << endl;
                   }

               else{
                   cout << currentFile.first.toStdString() << " - " <<  "0%"  << endl;
                   }
           }
       }
       if(Size==0)
       {
           x = 100;
       }
       cout << "Full directory size: " << x << "%" << endl;
   }
}*/

int main(int argc, char *argv[])
{
    /*ByFolder_CalculationStrategy * str1 = new ByFolder_CalculationStrategy;
    ByFileType_CalculationStrategy* str2 = new ByFileType_CalculationStrategy;

    QString dir("D:/qTREPOS/test/1");
    //QString dir("D:/qTREPOS/test/2");
    //QString path("D:/qTREPOS/AdressBook_1");

    cout << "STR1" << endl;
    PrintInfo(dir,str1);
    cout << "STR2" << endl;
    PrintInfo(dir,str2);
*/

    QApplication a(argc,argv);
    MainWindow s;
    s.show();
    return a.exec();
}
