#include "todofiltermodel.h"
#include "todomodel.h"

ToDoFilterModel::ToDoFilterModel(QObject *parent)
    : QSortFilterProxyModel(parent), m_showActive(true)
{
}

bool ToDoFilterModel::showActive() const
{
    return m_showActive;
}

void ToDoFilterModel::setShowActive(bool active)
{
    if (m_showActive != active) {
        m_showActive = active;
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
    return m_showActive ? isActive : !isActive;
}
