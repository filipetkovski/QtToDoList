#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>
#include <QtCore/qhash.h>
#include <QtCore/qstring.h>

namespace QmlCacheGeneratedCode {
namespace _qt_qml_TodoProject_qml_Main_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_TodoProject_qml_customcomponents_Header_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_TodoProject_qml_screens_ToDoListScreen_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_TodoProject_qml_screens_HomeScreen_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_TodoProject_qml_screens_CreateListScreen_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_TodoProject_qml_customcomponents_InputField_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_TodoProject_qml_customcomponents_ConfirmButton_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_TodoProject_qml_screens_EditListScreen_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_TodoProject_qml_customcomponents_TextButton_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_TodoProject_qml_customcomponents_ActiveTasksComponent_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/TodoProject/qml/Main.qml"), &QmlCacheGeneratedCode::_qt_qml_TodoProject_qml_Main_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/TodoProject/qml/customcomponents/Header.qml"), &QmlCacheGeneratedCode::_qt_qml_TodoProject_qml_customcomponents_Header_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/TodoProject/qml/screens/ToDoListScreen.qml"), &QmlCacheGeneratedCode::_qt_qml_TodoProject_qml_screens_ToDoListScreen_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/TodoProject/qml/screens/HomeScreen.qml"), &QmlCacheGeneratedCode::_qt_qml_TodoProject_qml_screens_HomeScreen_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/TodoProject/qml/screens/CreateListScreen.qml"), &QmlCacheGeneratedCode::_qt_qml_TodoProject_qml_screens_CreateListScreen_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/TodoProject/qml/customcomponents/InputField.qml"), &QmlCacheGeneratedCode::_qt_qml_TodoProject_qml_customcomponents_InputField_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/TodoProject/qml/customcomponents/ConfirmButton.qml"), &QmlCacheGeneratedCode::_qt_qml_TodoProject_qml_customcomponents_ConfirmButton_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/TodoProject/qml/screens/EditListScreen.qml"), &QmlCacheGeneratedCode::_qt_qml_TodoProject_qml_screens_EditListScreen_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/TodoProject/qml/customcomponents/TextButton.qml"), &QmlCacheGeneratedCode::_qt_qml_TodoProject_qml_customcomponents_TextButton_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/TodoProject/qml/customcomponents/ActiveTasksComponent.qml"), &QmlCacheGeneratedCode::_qt_qml_TodoProject_qml_customcomponents_ActiveTasksComponent_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.structVersion = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appTodoProject)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appTodoProject))
int QT_MANGLE_NAMESPACE(qCleanupResources_qmlcache_appTodoProject)() {
    return 1;
}
