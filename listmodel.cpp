#include "listmodel.h"
#include "taskmodel.h"

ListModel::ListModel(const QString &name, QObject *parent) : QAbstractListModel(parent),
    name(name)
{
}

QString ListModel::getName() const
{
    return name;
}

void ListModel::setName(const QString &newName)
{
    if (name == newName)
        return;
    name = newName;
    emit nameChanged();
}

QString ListModel::getDescription() const
{
    return description;
}

int ListModel::getListSize() const
{
    return tasks_list.size();
}

void ListModel::setDescription(const QString &newDescription)
{
    if (description == newDescription)
        return;
    description = newDescription;
    emit descriptionChanged();
}

int ListModel::getTasksLeft() const
{
    int count = 0;
    for(TaskModel task: tasks_list) {
        if(!task.is_done)
            count++;
    }
    return count;
}

int ListModel::rowCount(const QModelIndex &parent) const
{
    return tasks_list.size();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    const TaskModel& task = tasks_list[index.row()];

    switch (role)
    {
        case RoleName: return task.name;
        case RoleIsDone: return task.is_done;
    }

    return QVariant();
}

QHash<int, QByteArray> ListModel::roleNames() const
{
    return {
        {RoleName, "RoleName"},
        {RoleIsDone, "RoleIsDone"}
    };
}

void ListModel::addTask(const QString& name) {
    beginInsertRows(QModelIndex(), tasks_list.size(), tasks_list.size());
    TaskModel new_task;
    new_task.name = name;
    tasks_list.append(new_task);
    emit dataChanged(index(tasks_list.size()),index(tasks_list.size()));
    endInsertRows();
}

void ListModel::changeStatus(int idX, bool isChecked)
{
    if (idX >= 0 && idX < tasks_list.size())
    {
        if(tasks_list[idX].is_done != isChecked) {
            tasks_list[idX].is_done = isChecked;
            emit dataChanged(index(idX),index(idX));
        }
    }
}
