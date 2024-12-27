#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "todomodel.h"
#include "todofiltermodel.h"
#include "listfiltermodel.h"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    qmlRegisterType<ToDoModel>("ToDoModel",1,0,"ToDoModel");
    qmlRegisterType<ToDoFilterModel>("ToDoModel",1,0,"ToDoFilterModel");
    qmlRegisterType<ListFilterModel>("ListModel",1,0,"ListFilterModel");

    QQmlApplicationEngine engine;

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("TodoProject", "Main");

    return app.exec();
}
