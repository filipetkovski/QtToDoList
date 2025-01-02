#include "taskmodel.h"

TaskModel::TaskModel(QString name)
    : name(std::move(name)), isDone(false) {}


