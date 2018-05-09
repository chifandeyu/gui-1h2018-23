/****************************************************************************
** Meta object code from reading C++ file 'objectpainter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Src/objectpainter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'objectpainter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ObjectPainter_t {
    QByteArrayData data[10];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ObjectPainter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ObjectPainter_t qt_meta_stringdata_ObjectPainter = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ObjectPainter"
QT_MOC_LITERAL(1, 14, 13), // "slotGameTimer"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "paint"
QT_MOC_LITERAL(4, 35, 9), // "QPainter*"
QT_MOC_LITERAL(5, 45, 7), // "painter"
QT_MOC_LITERAL(6, 53, 31), // "const QStyleOptionGraphicsItem*"
QT_MOC_LITERAL(7, 85, 6), // "option"
QT_MOC_LITERAL(8, 92, 8), // "QWidget*"
QT_MOC_LITERAL(9, 101, 6) // "widget"

    },
    "ObjectPainter\0slotGameTimer\0\0paint\0"
    "QPainter*\0painter\0const QStyleOptionGraphicsItem*\0"
    "option\0QWidget*\0widget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ObjectPainter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    3,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 8,    5,    7,    9,

       0        // eod
};

void ObjectPainter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ObjectPainter *_t = static_cast<ObjectPainter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotGameTimer(); break;
        case 1: _t->paint((*reinterpret_cast< QPainter*(*)>(_a[1])),(*reinterpret_cast< const QStyleOptionGraphicsItem*(*)>(_a[2])),(*reinterpret_cast< QWidget*(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ObjectPainter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ObjectPainter.data,
      qt_meta_data_ObjectPainter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ObjectPainter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ObjectPainter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ObjectPainter.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return QObject::qt_metacast(_clname);
}

int ObjectPainter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
