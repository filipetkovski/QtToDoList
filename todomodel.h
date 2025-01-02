#ifndef TODOMODEL_H
#define TODOMODEL_H

#include "listmodel.h"

#include <QAbstractListModel>
#include <QObject>

class ToDoModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles
    {
        RoleActiveListName = Qt::ItemDataRole::UserRole,
        RoleInactiveListName,
        RoleTasksLeft
    };
    explicit ToDoModel(QObject *parent = nullptr);
    ~ToDoModel();

    Q_INVOKABLE void addList(const QString &name);
    Q_INVOKABLE ListModel* getListModel(int id) const;
    Q_INVOKABLE void deleteList(int index);
    Q_INVOKABLE int getListSize() const;

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<ListModel*> mTodoLists;
};

#endif // TODOMODEL_H
