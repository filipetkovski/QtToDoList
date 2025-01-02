#include "listmodel.h"

#include "taskmodel.h"

ListModel::ListModel(const QString &title, QObject *parent) : QAbstractListModel(parent),
    mTitle(title)
{
}

QString ListModel::getTitle() const
{
    return mTitle;
}

void ListModel::setTitle(const QString &newTitle)
{
    if (mTitle == newTitle)
        return;
    mTitle = newTitle;
    emit titleChanged();
}

QString ListModel::getDescription() const
{
    return mDescription;
}

int ListModel::getListSize() const
{
    return mTasksList.size();
}

void ListModel::setDescription(const QString &newDescription)
{
    if (mDescription == newDescription)
        return;
    mDescription = newDescription;
    emit descriptionChanged();
}

int ListModel::getTasksLeft() const
{
    int count = 0;
    for(TaskModel task: mTasksList)
    {
        if(!task.isDone)
            count++;
    }
    return count;
}

int ListModel::rowCount(const QModelIndex &parent) const
{
    return mTasksList.size();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    const TaskModel& task = mTasksList[index.row()];

    switch (role)
    {
        case RoleTaskName: return task.name;
        case RoleIsDone: return task.isDone;
    }

    return QVariant();
}

QHash<int, QByteArray> ListModel::roleNames() const
{
    return
    {
        {RoleTaskName, "RoleTaskName"},
        {RoleIsDone, "RoleIsDone"}
    };
}

void ListModel::addTask(const QString& title) {
    beginInsertRows(QModelIndex(), mTasksList.size(), mTasksList.size());
    TaskModel newTask(title);
    mTasksList.append(newTask);
    emit dataChanged(index(mTasksList.size()),index(mTasksList.size()));
    endInsertRows();
}

void ListModel::changeTaskStatus(int taskIndex, bool isChecked)
{
    if (taskIndex >= 0 && taskIndex < mTasksList.size())
    {
        if(mTasksList[taskIndex].isDone != isChecked)
        {
            mTasksList[taskIndex].isDone = isChecked;
            emit dataChanged(index(taskIndex),index(taskIndex));
        }
    }
}

void ListModel::reorderTasks(int fromIndex, int toIndex)
{
    if(fromIndex != toIndex)
    {
        beginMoveRows(QModelIndex(), fromIndex, fromIndex, QModelIndex(), toIndex+1);
        mTasksList.move(fromIndex, toIndex);
        endMoveRows();
    }
}

void ListModel::editTitleAndDescription(const QString& title, const QString& description, int taskIndex)
{
    if(title != "")
        setTitle(title);

    if(description != "")
        setDescription(description);

    emit dataChanged(index(taskIndex),index(taskIndex));
}

void ListModel::updateEditTasks(int taskIndex, const QString &newText)
{
    if(taskIndex >= 0 && taskIndex < mTasksList.size())
    {
        mTasksList[taskIndex].name = newText;
        emit dataChanged(index(taskIndex),index(taskIndex));
    }
}

void ListModel::deleteTask(int taskIndex)
{
    if(taskIndex >= 0 && taskIndex < mTasksList.size())
    {
        beginRemoveRows(QModelIndex(), taskIndex,taskIndex);
        mTasksList.removeAt(taskIndex);
        endRemoveRows();
        emit dataChanged(index(taskIndex),index(taskIndex));
    }
}
