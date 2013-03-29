#include <QtGui>
#include "fimage.h"
#include <iostream>
#include <string>

using namespace std;

#include <stdio.h>

FImage::FImage (int newIndex, QWidget *parent)
    : QLabel(parent)
{
    index = newIndex;
    isSelected = false;
    savedOriginal = false;
}

/*
const FImage& FImage :: operator=(const FImage& f)
{
    if(f.isSelected == NULL)
        cout << "error" << endl;
    else
    isSelected = f.isSelected;
    index = f.index;
    return *this;
}
*/

FImage::~FImage()
{
}

void FImage::setSelected()
{
    cout << "Image " << index << " is selected" << endl;
    if(!savedOriginal)
    {
        original = *this->pixmap();
        savedOriginal = true;
    }
    isSelected = true;
    QPixmap tempPixmap;
    tempPixmap = *this->pixmap();
    icon = new QIcon(tempPixmap);
    QPixmap temp = icon->pixmap(QSize(100,100), QIcon::Disabled, QIcon::On);
    this->setPixmap(temp);
    emit(isSelectedSignal(index));
}

void FImage::setUnselected()
{
    cout << "Image " << index << " is unselected" << endl;
    isSelected = false;
    QPixmap tempPixmap;
    tempPixmap = *this->pixmap();
    icon = new QIcon(tempPixmap);
    QPixmap temp = icon->pixmap(QSize(100,100), QIcon::Normal, QIcon::On);
    this->setPixmap(original);
    emit(isUnselectedSignal(index));
}

void FImage::mouseReleaseEvent(QMouseEvent *event)
 {
     if (event->button() == Qt::LeftButton)
     {
         cout << "Image " << index << " has been clicked" << endl;
         if(isSelected)
         {
             isSelected = false;
             setUnselected();
         }
         else
         {
             isSelected = true;
             setSelected();
         }
     }
 }
