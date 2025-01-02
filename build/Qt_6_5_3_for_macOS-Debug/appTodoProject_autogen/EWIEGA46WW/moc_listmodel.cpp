/****************************************************************************
** Meta object code from reading C++ file 'listmodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../listmodel.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSListModelENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSListModelENDCLASS = QtMocHelpers::stringData(
    "ListModel",
    "titleChanged",
    "",
    "descriptionChanged",
    "addTask",
    "title",
    "changeTaskStatus",
    "index",
    "isChecked",
    "reorderTasks",
    "fromIndex",
    "toIndex",
    "editTitleAndDescription",
    "description",
    "taskIndex",
    "updateEditTasks",
    "newText",
    "deleteTask",
    "mTitle",
    "mDescription"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSListModelENDCLASS_t {
    uint offsetsAndSizes[40];
    char stringdata0[10];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[8];
    char stringdata5[6];
    char stringdata6[17];
    char stringdata7[6];
    char stringdata8[10];
    char stringdata9[13];
    char stringdata10[10];
    char stringdata11[8];
    char stringdata12[24];
    char stringdata13[12];
    char stringdata14[10];
    char stringdata15[16];
    char stringdata16[8];
    char stringdata17[11];
    char stringdata18[7];
    char stringdata19[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSListModelENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSListModelENDCLASS_t qt_meta_stringdata_CLASSListModelENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "ListModel"
        QT_MOC_LITERAL(10, 12),  // "titleChanged"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 18),  // "descriptionChanged"
        QT_MOC_LITERAL(43, 7),  // "addTask"
        QT_MOC_LITERAL(51, 5),  // "title"
        QT_MOC_LITERAL(57, 16),  // "changeTaskStatus"
        QT_MOC_LITERAL(74, 5),  // "index"
        QT_MOC_LITERAL(80, 9),  // "isChecked"
        QT_MOC_LITERAL(90, 12),  // "reorderTasks"
        QT_MOC_LITERAL(103, 9),  // "fromIndex"
        QT_MOC_LITERAL(113, 7),  // "toIndex"
        QT_MOC_LITERAL(121, 23),  // "editTitleAndDescription"
        QT_MOC_LITERAL(145, 11),  // "description"
        QT_MOC_LITERAL(157, 9),  // "taskIndex"
        QT_MOC_LITERAL(167, 15),  // "updateEditTasks"
        QT_MOC_LITERAL(183, 7),  // "newText"
        QT_MOC_LITERAL(191, 10),  // "deleteTask"
        QT_MOC_LITERAL(202, 6),  // "mTitle"
        QT_MOC_LITERAL(209, 12)   // "mDescription"
    },
    "ListModel",
    "titleChanged",
    "",
    "descriptionChanged",
    "addTask",
    "title",
    "changeTaskStatus",
    "index",
    "isChecked",
    "reorderTasks",
    "fromIndex",
    "toIndex",
    "editTitleAndDescription",
    "description",
    "taskIndex",
    "updateEditTasks",
    "newText",
    "deleteTask",
    "mTitle",
    "mDescription"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSListModelENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       2,   92, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    3 /* Public */,
       3,    0,   63,    2, 0x06,    4 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   64,    2, 0x02,    5 /* Public */,
       6,    2,   67,    2, 0x02,    7 /* Public */,
       9,    2,   72,    2, 0x02,   10 /* Public */,
      12,    3,   77,    2, 0x02,   13 /* Public */,
      15,    2,   84,    2, 0x02,   17 /* Public */,
      17,    1,   89,    2, 0x02,   20 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    5,   13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   14,   16,
    QMetaType::Void, QMetaType::Int,   14,

 // properties: name, type, flags
      18, QMetaType::QString, 0x00015803, uint(0), 0,
      19, QMetaType::QString, 0x00015803, uint(1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject ListModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_CLASSListModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSListModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSListModelENDCLASS_t,
        // property 'mTitle'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'mDescription'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ListModel, std::true_type>,
        // method 'titleChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'descriptionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addTask'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'changeTaskStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'reorderTasks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'editTitleAndDescription'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateEditTasks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'deleteTask'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void ListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ListModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->titleChanged(); break;
        case 1: _t->descriptionChanged(); break;
        case 2: _t->addTask((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->changeTaskStatus((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 4: _t->reorderTasks((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->editTitleAndDescription((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 6: _t->updateEditTasks((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 7: _t->deleteTask((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ListModel::*)();
            if (_t _q_method = &ListModel::titleChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ListModel::*)();
            if (_t _q_method = &ListModel::descriptionChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ListModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getTitle(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getDescription(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ListModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTitle(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setDescription(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *ListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSListModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int ListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ListModel::titleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ListModel::descriptionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
