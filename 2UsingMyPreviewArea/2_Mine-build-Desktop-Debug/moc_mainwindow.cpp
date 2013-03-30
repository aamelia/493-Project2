/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Mar 30 03:03:28 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../2_Mine/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      28,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   11,   11,   11, 0x0a,
      56,   11,   11,   11, 0x0a,
      73,   11,   11,   11, 0x0a,
      88,   11,   11,   11, 0x0a,
     102,   11,   11,   11, 0x0a,
     142,  133,   11,   11, 0x0a,
     162,   11,   11,   11, 0x0a,
     200,  183,   11,   11, 0x0a,
     221,   11,   11,   11, 0x0a,
     240,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0replaceBottom()\0"
    "deletedFromMain(int)\0quit()\0"
    "flickrCallback()\0createFlickr()\0"
    "createMenus()\0processDownloadedPics(QPixmap)\0"
    "location\0resetMainImage(int)\0"
    "mainStartAnimation()\0collectionNumber\0"
    "resetCollection(int)\0deleteCollection()\0"
    "deleteSelection()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->replaceBottom(); break;
        case 1: _t->deletedFromMain((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->quit(); break;
        case 3: _t->flickrCallback(); break;
        case 4: _t->createFlickr(); break;
        case 5: _t->createMenus(); break;
        case 6: _t->processDownloadedPics((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 7: _t->resetMainImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->mainStartAnimation(); break;
        case 9: _t->resetCollection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->deleteCollection(); break;
        case 11: _t->deleteSelection(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::replaceBottom()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainWindow::deletedFromMain(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
