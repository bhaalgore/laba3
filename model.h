#ifndef FILESMODEL_H
#define FILESMODEL_H

#include <QList>
#include <QAbstractTableModel>

#include "initdata.h"

class Model : public QAbstractTableModel
{
   public:
    Model(QObject *parent, QList<InitData> model = QList<InitData>());


    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &ix, int role) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;

    void setModel(QList<InitData> model);

   private:
    enum ColumnName {
    NAME,
    SIZE,
    PERCENT
    };

    QList<InitData> model_;

};
#endif // FILESMODEL_H
