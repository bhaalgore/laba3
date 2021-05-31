#include "calculationstrategy.h"

double CalculationStrategy::FullDirSize(QString Dir)
{
    double DirectorySize = 0;
    QDir directory(Dir);
    QFileInfoList entryList = directory.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    for(auto &currentFile : entryList)
    {
        if(currentFile.isDir())
            DirectorySize += FullDirSize(Dir + '/' +currentFile.fileName());
        else
            DirectorySize += currentFile.size();
    }
    return DirectorySize;
}
