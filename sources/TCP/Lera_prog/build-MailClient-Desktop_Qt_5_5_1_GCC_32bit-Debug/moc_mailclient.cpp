/****************************************************************************
** Meta object code from reading C++ file 'mailclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MailClient/mailclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mailclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MailClient_t {
    QByteArrayData data[15];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MailClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MailClient_t qt_meta_stringdata_MailClient = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MailClient"
QT_MOC_LITERAL(1, 11, 13), // "slotReadyRead"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "slotError"
QT_MOC_LITERAL(4, 36, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(5, 65, 13), // "slotConnected"
QT_MOC_LITERAL(6, 79, 15), // "parssingMessage"
QT_MOC_LITERAL(7, 95, 3), // "str"
QT_MOC_LITERAL(8, 99, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 121, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(10, 145, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(11, 167, 4), // "arg1"
QT_MOC_LITERAL(12, 172, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(13, 196, 23), // "on_comboBox_2_activated"
QT_MOC_LITERAL(14, 220, 23) // "on_pushButton_3_clicked"

    },
    "MailClient\0slotReadyRead\0\0slotError\0"
    "QAbstractSocket::SocketError\0slotConnected\0"
    "parssingMessage\0str\0on_pushButton_clicked\0"
    "on_pushButton_4_clicked\0on_comboBox_activated\0"
    "arg1\0on_pushButton_2_clicked\0"
    "on_comboBox_2_activated\0on_pushButton_3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MailClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    1,   65,    2, 0x08 /* Private */,
       5,    0,   68,    2, 0x08 /* Private */,
       6,    1,   69,    2, 0x08 /* Private */,
       8,    0,   72,    2, 0x08 /* Private */,
       9,    0,   73,    2, 0x08 /* Private */,
      10,    1,   74,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,
      13,    1,   78,    2, 0x08 /* Private */,
      14,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

void MailClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MailClient *_t = static_cast<MailClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotReadyRead(); break;
        case 1: _t->slotError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 2: _t->slotConnected(); break;
        case 3: { QString _r = _t->parssingMessage((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_pushButton_4_clicked(); break;
        case 6: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        case 8: _t->on_comboBox_2_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject MailClient::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MailClient.data,
      qt_meta_data_MailClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MailClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MailClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MailClient.stringdata0))
        return static_cast<void*>(const_cast< MailClient*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MailClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
