/****************************************************************************
** Meta object code from reading C++ file 'fimage.h'
**
** Created: Fri Mar 29 13:39:48 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../2_Mine/fimage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fimage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FImage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      30,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      54,    7,    7,    7, 0x0a,
      68,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FImage[] = {
    "FImage\0\0isSelectedSignal(int)\0"
    "isUnselectedSignal(int)\0setSelected()\0"
    "setUnselected()\0"
};

void FImage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FImage *_t = static_cast<FImage *>(_o);
        switch (_id) {
        case 0: _t->isSelectedSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->isUnselectedSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setSelected(); break;
        case 3: _t->setUnselected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FImage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FImage::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_FImage,
      qt_meta_data_FImage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FImage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FImage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FImage))
        return static_cast<void*>(const_cast< FImage*>(this));
    return QLabel::qt_metacast(_clname);
}

int FImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void FImage::isSelectedSignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FImage::isUnselectedSignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
