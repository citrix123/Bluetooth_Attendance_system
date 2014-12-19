/****************************************************************************
** Meta object code from reading C++ file 'advance.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SmartAttendence/advance.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'advance.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Advance_t {
    QByteArrayData data[15];
    char stringdata[284];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Advance_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Advance_t qt_meta_stringdata_Advance = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 21),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 5),
QT_MOC_LITERAL(4, 37, 15),
QT_MOC_LITERAL(5, 53, 19),
QT_MOC_LITERAL(6, 73, 21),
QT_MOC_LITERAL(7, 95, 23),
QT_MOC_LITERAL(8, 119, 34),
QT_MOC_LITERAL(9, 154, 32),
QT_MOC_LITERAL(10, 187, 18),
QT_MOC_LITERAL(11, 206, 23),
QT_MOC_LITERAL(12, 230, 3),
QT_MOC_LITERAL(13, 234, 26),
QT_MOC_LITERAL(14, 261, 21)
    },
    "Advance\0on_comboBox_activated\0\0index\0"
    "on_back_clicked\0on_Id_returnPressed\0"
    "on_Id_editingFinished\0on_name_editingFinished\0"
    "on_Leave_Slots_currentIndexChanged\0"
    "on_LeaveType_currentIndexChanged\0"
    "on_proceed_clicked\0on_Datefrom_dateChanged\0"
    "dat\0on_tableView_doubleClicked\0"
    "on_savetofile_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Advance[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08,
       4,    0,   72,    2, 0x08,
       5,    0,   73,    2, 0x08,
       6,    0,   74,    2, 0x08,
       7,    0,   75,    2, 0x08,
       8,    1,   76,    2, 0x08,
       9,    1,   79,    2, 0x08,
      10,    0,   82,    2, 0x08,
      11,    1,   83,    2, 0x08,
      13,    1,   86,    2, 0x08,
      14,    0,   89,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,   12,
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,

       0        // eod
};

void Advance::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Advance *_t = static_cast<Advance *>(_o);
        switch (_id) {
        case 0: _t->on_comboBox_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_back_clicked(); break;
        case 2: _t->on_Id_returnPressed(); break;
        case 3: _t->on_Id_editingFinished(); break;
        case 4: _t->on_name_editingFinished(); break;
        case 5: _t->on_Leave_Slots_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_LeaveType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_proceed_clicked(); break;
        case 8: _t->on_Datefrom_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 9: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->on_savetofile_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Advance::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Advance.data,
      qt_meta_data_Advance,  qt_static_metacall, 0, 0}
};


const QMetaObject *Advance::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Advance::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Advance.stringdata))
        return static_cast<void*>(const_cast< Advance*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Advance::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
