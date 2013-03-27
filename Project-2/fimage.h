#ifndef FIMAGE_H
#define FIMAGE_H

#include <QtGui>
#include <QtNetwork>
#include <iostream>
#include <string>

class FImage: public QLabel
{
public:
    FImage(int newIndex);
    ~FImage();

protected:
    int index;

public slots:

signals:

};

#endif // FIMAGE_H
