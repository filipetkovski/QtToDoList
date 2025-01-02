#include "listfiltermodel.h"

#include "listmodel.h"

ListFilterModel::ListFilterModel(QObject *parent)
    : QSortFilterProxyModel(parent), mShowActive(true)
{
}

bool ListFilterModel::showActive() const
{
    return mShowActive;
}

void ListFilterModel::setShowActive(bool active)
{
    if (mShowActive != active) {
        mShowActive = active;
        invalidateFilter();
        emit showActiveChanged();
    }
}

int ListFilterModel::sourceIndex(int indX)
{
    return mapToSource(index(indX,0)).row();
}

bool ListFilterModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);

    bool isActive = sourceModel()->data(index, ListModel::RoleIsDone).toBool();
    return mShowActive ? !isActive : isActive;
}


