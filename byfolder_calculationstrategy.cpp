#include "byfolder_calculationstrategy.h"



QList<InitData> ByFolder_CalculationStrategy::CalculationMethod(const QString& path)
{
QDir directory(path);
QFileInfoList FilesList = directory.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
QList<InitData> FilesSizeList;
    if(directory.exists())
    {
        QFileInfoList FilesList = directory.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
        double dSize = this->FullDirSize(path);
        for (QFileInfo &currentFile : FilesList)
        {
            double FileSize;
            if(currentFile.isDir())
                FileSize = this->FullDirSize(path + '/' +currentFile.fileName());
            else
                FileSize = (double)currentFile.size();
            FilesSizeList.push_back(InitData(currentFile.fileName(),FileSize, FileSize/dSize));
        }
       return FilesSizeList;
    }
    else
        throw QString("Error: non-existent directory.");
}



