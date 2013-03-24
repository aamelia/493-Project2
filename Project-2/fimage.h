#ifndef FIMAGE_H
#define FIMAGE_H

#include <QtGui>
#include <QtNetwork>
#include <iostream>
#include <string>

class FImage: public QLabel
{
    Q_OBJECT

public:
    FImage();
    FImage(int index);

protected:
    int index;

public slots:

signals:

};

#endif // FIMAGE_H
