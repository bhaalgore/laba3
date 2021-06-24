#include "byfiletype_calculationstrategy.h"

QList<InitData> ByFileType_CalculationStrategy::CalculationMethod(const QString& path)
{
    QDir directory(path);
    if(directory.exists())
    {
    QFileInfoList FilesList = directory.entryInfoList(QDir::Files);
    QFileInfoList directoryList = directory.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList::iterator iterator = directoryList.begin();;
    for(int i = 0; i < directoryList.size(); i++)
    {
        FilesList += QDir(directoryList[i].absoluteFilePath()).entryInfoList(QDir::Files);
        directoryList += QDir(directoryList[i].absoluteFilePath()).entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    }
    QList <QString> typesList;
    iterator = FilesList.begin();
    while(iterator != FilesList.end())
    {
        if(!typesList.contains(iterator->suffix()))
            typesList.push_back(iterator->suffix());
        iterator++;
    }
    QString currentSuffix;
    QList<InitData> typesSizeList;
    double directorySize = this->FullDirSize(path);
    for (QString &type : typesList)
    {
        currentSuffix = type;
        typesSizeList.append(InitData(currentSuffix,0,0));
        for (QFileInfo &curItem : FilesList)
        {
            if(curItem.suffix() == currentSuffix)
            typesSizeList.last().size_ += curItem.size();
        }
           typesSizeList.last().percent_ = typesSizeList.last().size_ / directorySize;
    }
            return typesSizeList;
    }
    else
        throw QString("directory does not exist");
}
