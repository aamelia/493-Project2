#ifndef FIMAGE_H
#define FIMAGE_H

#include <QtGui>
#include <QtNetwork>
#include <iostream>
#include <string>
using namespace std;

class FImage: public QLabel
{
    Q_OBJECT

public:
    FImage(int newIndex, QWidget *parent=0);
    ~FImage();
    const FImage& operator=(const FImage& f);
    int index;
    bool isSelected;
    void setIndex(int newIndex);

private:
    void mouseReleaseEvent(QMouseEvent *event);
    QPixmap original;
    bool savedOriginal;
    QIcon *icon;

public slots:
    void setSelected();
    void setUnselected();

signals:
    void isSelectedSignal(int);
    void isUnselectedSignal(int);

};
#endif // FIMAGE_H
