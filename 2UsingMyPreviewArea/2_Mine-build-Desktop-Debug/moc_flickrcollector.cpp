/****************************************************************************
** Meta object code from reading C++ file 'flickrcollector.h'
**
** Created: Fri Mar 29 22:53:36 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../2_Mine/flickrcollector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flickrcollector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FlickrCollector[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      25,   16,   16,   16, 0x0a,
      41,   35,   16,   16, 0x0a,
      74,   16,   16,   16, 0x0a,
      94,   86,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FlickrCollector[] = {
    "FlickrCollector\0\0ready()\0execute()\0"
    "reply\0downloadFinished(QNetworkReply*)\0"
    "printList()\0subRoot\0printDomTree(QDomElement)\0"
};

void FlickrCollector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FlickrCollector *_t = static_cast<FlickrCollector *>(_o);
        switch (_id) {
        case 0: _t->ready(); break;
        case 1: _t->execute(); break;
        case 2: _t->downloadFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->printList(); break;
        case 4: _t->printDomTree((*reinterpret_cast< QDomElement(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FlickrCollector::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FlickrCollector::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FlickrCollector,
      qt_meta_data_FlickrCollector, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FlickrCollector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FlickrCollector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FlickrCollector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FlickrCollector))
        return static_cast<void*>(const_cast< FlickrCollector*>(this));
    return QObject::qt_metacast(_clname);
}

int FlickrCollector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FlickrCollector::ready()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
