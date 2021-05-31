#include "byfolder_calculationstrategy.h"



QList<std::pair<QString,double>> ByFolder_CalculationStrategy::CalculationMethod(const QString& path)
{
QDir directory(path);
QFileInfoList FilesList = directory.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
QList<std::pair<QString,double>> FilesSizeList;
    if(directory.exists())
    {
        QFileInfoList FilesList = directory.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
        for (QFileInfo &currentFile : FilesList)
        {
            double FileSize;
            if(currentFile.isDir())
                FileSize = this->FullDirSize(path + '/' +currentFile.fileName());
            else
                FileSize = (double)currentFile.size();
            FilesSizeList.push_back(std::pair<QString,double> (currentFile.fileName(),FileSize));
        }
       return FilesSizeList;
    }
    else
        throw QString("Error: non-existent directory.");
}



