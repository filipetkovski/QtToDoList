#ifndef TASKMODEL_H
#define TASKMODEL_H

#include <QObject>

struct TaskModel {
    explicit TaskModel(QString name);

    QString name;
    bool isDone;
};

#endif // TASKMODEL_H
