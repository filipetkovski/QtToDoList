#include "todomodel.h"
#include "listmodel.h"

ToDoModel::ToDoModel(QObject *parent) : QAbstractListModel(parent)
{
    addList("Task 1");
    addList("Task 2");
    addList("Task 3");
    addList("Task 4");
    addList("Task 5");
    addList("Task 6");
    addList("Task 7");
    addList("Task 8");
    addList("Task 9");
    addList("Task 10");
    addList("Task 11");
    addList("Task 12");

    todo_lists[0]->addTask("Make the bed 1");
    todo_lists[0]->addTask("Make the bed 2");
    todo_lists[0]->addTask("Make the bed 3");

    todo_lists[1]->addTask("Make the bed 1");
    todo_lists[1]->addTask("Make the bed 2");

    todo_lists[2]->addTask("Make the bed 1");
    todo_lists[2]->addTask("Make the bed 2");
    todo_lists[2]->addTask("Make the bed 3");
    todo_lists[2]->addTask("Make the bed 4");
    todo_lists[2]->addTask("Make the bed 5");
    todo_lists[2]->addTask("Make the bed 6");
    todo_lists[2]->addTask("Make the bed 7");
}

ToDoModel::~ToDoModel()
{
    for(ListModel* list_model : todo_lists) {
        delete list_model;
    }
}

void ToDoModel::addList(const QString &name)
{
    beginInsertRows(QModelIndex(), todo_lists.size(),todo_lists.size());

    ListModel *list_model = new ListModel(name);
    todo_lists.append(list_model);
    connect(list_model,&ListModel::dataChanged,this,[this,list_model](){
        int idX = todo_lists.indexOf(list_model);
        emit dataChanged(index(idX),index(idX));
    });

    endInsertRows();
}

ListModel *ToDoModel::getListModel(int index) const
{
    if (index < 0 || index >= todo_lists.size())
        return nullptr;

    return todo_lists.at(index);
}

void ToDoModel::deleteList(int index)
{
    if (index >= 0 && index < todo_lists.size())
    {
        beginRemoveRows(QModelIndex(), index,index);
        delete todo_lists[index];
        todo_lists.removeAt(index);
        endRemoveRows();
    }
}

int ToDoModel::getListSize() const
{
    return todo_lists.size();
}

int ToDoModel::rowCount(const QModelIndex &parent) const
{
    return todo_lists.size();
}

QVariant ToDoModel::data(const QModelIndex &index, int role) const
{
    const ListModel &list = *todo_lists[index.row()];
    int tasks_left = list.getTasksLeft();
    int tasks_size = list.getListSize();

    switch (role)
    {
        case RoleActiveListName: return tasks_left > 0 || tasks_size == 0 ? list.getName() : QVariant();
        case RoleInactiveListName: return tasks_left == 0 && tasks_size > 0 ? list.getName() : QVariant();
        case RoleTasksLeft: return tasks_left > 0 || tasks_size == 0 ? tasks_left : QVariant();
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


