#include "todofiltermodel.h"

#include "todomodel.h"

ToDoFilterModel::ToDoFilterModel(QObject *parent)
    : QSortFilterProxyModel(parent), mShowActive(true)
{
}

bool ToDoFilterModel::showActive() const
{
    return mShowActive;
}

void ToDoFilterModel::setShowActive(bool active)
{
    if (mShowActive != active) {
        mShowActive = active;
        invalidateFilter();
        emit showActiveChanged();
    }
}

int ToDoFilterModel::sourceIndex(int indX)
{
    return mapToSource(index(indX,0)).row();
}

bool ToDoFilterModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);

    bool isActive = sourceModel()->data(index, ToDoModel::RoleActiveListName).isValid();
    return mShowActive ? isActive : !isActive;
}
