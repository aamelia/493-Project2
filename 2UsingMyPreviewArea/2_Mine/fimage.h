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
    int index;
    bool isSelected;

protected:
    void mouseReleaseEvent(QMouseEvent *event);
    QPixmap original;
    bool savedOriginal;
    QIcon *icon;

public slots:
    void setSelected();
    void setUnselected();

signals:

};

#endif // FIMAGE_H
