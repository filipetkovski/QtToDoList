#include "todomodel.h"

#include "listmodel.h"

ToDoModel::ToDoModel(QObject *parent) : QAbstractListModel(parent)
{ 
}

ToDoModel::~ToDoModel()
{
    for(ListModel* listModel : mTodoLists)
        delete listModel;
}

void ToDoModel::addList(const QString &name)
{
    beginInsertRows(QModelIndex(), mTodoLists.size(),mTodoLists.size());

    ListModel *listModel = new ListModel(name);
    mTodoLists.append(listModel);
    connect(listModel,&ListModel::dataChanged,this,[this,listModel](){
        int idX = mTodoLists.indexOf(listModel);
        emit dataChanged(index(idX),index(idX));
    });

    endInsertRows();
}

ListModel *ToDoModel::getListModel(int index) const
{
    if (index < 0 || index >= mTodoLists.size())
        return nullptr;

    return mTodoLists.at(index);
}

void ToDoModel::deleteList(int index)
{
    if (index >= 0 && index < mTodoLists.size())
    {
        beginRemoveRows(QModelIndex(), index,index);
        delete mTodoLists[index];
        mTodoLists.removeAt(index);
        endRemoveRows();
    }
}

int ToDoModel::getListSize() const
{
    return mTodoLists.size();
}

int ToDoModel::rowCount(const QModelIndex &parent) const
{
    return mTodoLists.size();
}

QVariant ToDoModel::data(const QModelIndex &index, int role) const
{
    const ListModel &list = *mTodoLists[index.row()];
    int tasksLeft = list.getTasksLeft();
    int tasksSize = list.getListSize();

    switch (role)
    {
        case RoleActiveListName: return tasksLeft > 0 || tasksSize == 0 ? list.getTitle() : QVariant();
        case RoleInactiveListName: return tasksLeft == 0 && tasksSize > 0 ? list.getTitle() : QVariant();
        case RoleTasksLeft: return tasksLeft > 0 || tasksSize == 0 ? tasksLeft : QVariant();
    }

    return QVariant();
}

QHash<int, QByteArray> ToDoModel::roleNames() const
{
    return {
        {RoleActiveListName, "RoleActiveListName"},
        {RoleInactiveListName, "RoleInactiveListName"},
        {RoleTasksLeft, "RoleTasksLeft"}
    };
}


