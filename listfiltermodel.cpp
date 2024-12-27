#include "listfiltermodel.h"
#include "listmodel.h"

ListFilterModel::ListFilterModel(QObject *parent)
    : QSortFilterProxyModel(parent), m_showActive(true)
{
}

bool ListFilterModel::showActive() const
{
    return m_showActive;
}

void ListFilterModel::setShowActive(bool active)
{
    if (m_showActive != active) {
        m_showActive = active;
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
    return m_showActive ? !isActive : isActive;
}


