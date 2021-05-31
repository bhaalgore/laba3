#include <iostream>

#include "calculationstrategy.h"
#include "byfolder_calculationstrategy.h"


using namespace std;

void PrintInfo(QString Dir, CalculationStrategy* strat)
{
   QList<pair<QString,double>> FilesList = strat->CalculationMethod(Dir);
   double Size = CalculationStrategy::FullDirSize(Dir);
   double x=0;
   if(FilesList.isEmpty())
       cout << "Directory is empty.";
   else{
       for(auto& currentFile : FilesList)
       {
           x = (currentFile.second)*100/Size + x;
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
       cout << "Full directory size: " << x << "%" << endl;
   }
};

int main(int argc, char *argv[])
{
    ByFolder_CalculationStrategy * str1 = new ByFolder_CalculationStrategy;

    QString path("D:/qTREPOS/AdressBook_1");
    PrintInfo(path,str1);



}
