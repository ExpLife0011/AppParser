/****************************************************************************
** Meta object code from reading C++ file 'callinfodlg.h'
**
** Created: Wed Apr 1 09:09:24 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "../../callinfodlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'callinfodlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CallInfoDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      54,   50,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CallInfoDlg[] = {
    "CallInfoDlg\0\0OnLstCallFriendsClicked(QModelIndex)\0"
    "key\0OnEdtFilterTextChanged(QString)\0"
};

void CallInfoDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CallInfoDlg *_t = static_cast<CallInfoDlg *>(_o);
        switch (_id) {
        case 0: _t->OnLstCallFriendsClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->OnEdtFilterTextChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CallInfoDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CallInfoDlg::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_CallInfoDlg,
      qt_meta_data_CallInfoDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CallInfoDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CallInfoDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CallInfoDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CallInfoDlg))
        return static_cast<void*>(const_cast< CallInfoDlg*>(this));
    return QFrame::qt_metacast(_clname);
}

int CallInfoDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
