#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>
#include <QObject>

#include "taskmodel.h"

class ListModel : public QAbstractListModel
{

    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString description READ getDescription WRITE setDescription NOTIFY descriptionChanged FINAL)

public:
    enum Roles {
        RoleName = Qt::ItemDataRole::UserRole,
        RoleIsDone,
    };

    ListModel(const QString &name, QObject *parent = nullptr);
    Q_INVOKABLE void addTask(const QString& name);
    Q_INVOKABLE void changeStatus(int index, bool isChecked);
    Q_INVOKABLE void reorderTasks(int index1, int index2);
    Q_INVOKABLE void editTasks(const QString& name, const QString& description, int indX);
    Q_INVOKABLE void updateEditTasks(int taskIndex, const QString& newText);
    Q_INVOKABLE void deleteTask(int taskIndex);


    QString getName() const;
    void setName(const QString &newName);
    QString getDescription() const;
    int getListSize() const;
    void setDescription(const QString &newDescription);
    int getTasksLeft() const;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:
    void nameChanged();
    void descriptionChanged();

private:
    QString name;
    QString description;
    QList<TaskModel> tasks_list;   
};

#endif // LISTMODEL_H
