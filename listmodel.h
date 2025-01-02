#ifndef LISTMODEL_H
#define LISTMODEL_H

#include "taskmodel.h"

#include <QAbstractListModel>
#include <QObject>

class ListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString mTitle READ getTitle WRITE setTitle NOTIFY titleChanged FINAL)
    Q_PROPERTY(QString mDescription READ getDescription WRITE setDescription NOTIFY descriptionChanged FINAL)

public:
    enum Roles
    {
        RoleTaskName = Qt::ItemDataRole::UserRole,
        RoleIsDone,
    };
    ListModel(const QString &name, QObject *parent = nullptr);

    Q_INVOKABLE void addTask(const QString& title);
    Q_INVOKABLE void changeTaskStatus(int taskIndex, bool isChecked);
    Q_INVOKABLE void reorderTasks(int fromIndex, int toIndex);
    Q_INVOKABLE void editTitleAndDescription(const QString& title, const QString& description, int taskIndex);
    Q_INVOKABLE void updateEditTasks(int taskIndex, const QString& newText);
    Q_INVOKABLE void deleteTask(int taskIndex);

    QString getTitle() const;
    void setTitle(const QString &newTitle);
    QString getDescription() const;
    int getListSize() const;
    void setDescription(const QString &newDescription);
    int getTasksLeft() const;

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:
    void titleChanged();
    void descriptionChanged();

private:
    QString mTitle;
    QString mDescription;
    QList<TaskModel> mTasksList;
};

#endif // LISTMODEL_H
