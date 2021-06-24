#include <cmath>

#include "model.h"
#include "calculationstrategy.h"
#include "byfiletype_calculationstrategy.h"
#include "byfolder_calculationstrategy.h"

Model::Model(QObject *parent, QList<InitData> model) : QAbstractTableModel(parent)//управляет данными
{
    model_ = model;
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Vertical) {
        return section;
    }

    switch (section) {
    case NAME:
        return "Name";
    case SIZE:
        return "Size";
    case PERCENT:
        return "Procent";
    }
    return QVariant();
}

QVariant Model::data(const QModelIndex &ix, int role) const
{
    if (model_.count() <= ix.row() || !ix.isValid() || ((role != Qt::DisplayRole) && (role != Qt::EditRole)))
    {
        return QVariant();
    }

    if (ix.column() == 0)
    {
        return model_[ix.row()].name_;
    }
    else if (ix.column() == 1)
    {
        return model_[ix.row()].size_;
    }
    else if (ix.column() == 2)
    {
        if(model_[ix.row()].size_ == 0)
            return 0;
        if(model_[ix.row()].percent_ < 0.0001)
         return "<0,01";

        return (model_[ix.row()].percent_*100);
    }
}

int Model::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return model_.count();
}

int Model::columnCount(const QModelIndex &parent) const
{
   Q_UNUSED(parent);
   return PERCENT+1;
}


void Model::setModel(QList<InitData> model)
{
    beginResetModel();
    model_ = model;
    endResetModel();
}
