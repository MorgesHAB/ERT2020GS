/****************************************************************************
** Meta object code from reading C++ file 'GuiWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UI/GuiWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GuiWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GuiWindow_t {
    QByteArrayData data[6];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GuiWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GuiWindow_t qt_meta_stringdata_GuiWindow = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GuiWindow"
QT_MOC_LITERAL(1, 10, 12), // "refresh_data"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "xbee_clicked"
QT_MOC_LITERAL(4, 37, 14), // "ignite_clicked"
QT_MOC_LITERAL(5, 52, 20) // "theme_change_clicked"

    },
    "GuiWindow\0refresh_data\0\0xbee_clicked\0"
    "ignite_clicked\0theme_change_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GuiWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GuiWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GuiWindow *_t = static_cast<GuiWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refresh_data(); break;
        case 1: _t->xbee_clicked(); break;
        case 2: _t->ignite_clicked(); break;
        case 3: _t->theme_change_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GuiWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GuiWindow.data,
      qt_meta_data_GuiWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GuiWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GuiWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GuiWindow.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui_Form"))
        return static_cast< Ui_Form*>(this);
    return QWidget::qt_metacast(_clname);
}

int GuiWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
