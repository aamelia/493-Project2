#include "previewarea.h"
#include <QtGui>
#include <QWidget>
#include <QLayout>
#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>


//Public
PreviewArea::PreviewArea (int size, QWidget *parent)
    : QScrollArea(parent)
{
    size = 10;
    itemNum = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTick()));
    startAnimation(2000);

    container = new QWidget;
    layout = new QHBoxLayout();

    FImage *temp;
    for(int i=0; i<10; i++)
    {
        temp = new FImage(i);
        temp->setFixedSize(100,100);
        temp->setScaledContents(true);
        layout->addWidget(temp);
        myLabels.push_back(temp);
        selectedLabels.push_back(false);
        connect(temp, SIGNAL(isSelectedSignal(int)), this, SLOT(setSelected(int)));
        connect(temp, SIGNAL(isUnselectedSignal(int)), this, SLOT(setUnselected(int)));
    }

    container->setLayout(layout);
    container->setMaximumHeight(110);
    this->setWidget(container);
}

void PreviewArea::addBlankImages(int num)
{
    FImage *temp;
    for(int i=0; i<num; i++)
    {
        temp = new FImage(i);
        temp->setFixedSize(100,100);
        temp->setScaledContents(true);
        layout->addWidget(temp);
        myLabels.push_back(temp);
    }
}

void PreviewArea::setSelected(int index)
{
    selectedLabels.at(index) = true;
}

void PreviewArea::setUnselected(int index)
{
    selectedLabels.at(index) = false;
    cout << "Set selectedLabels[" << index << "] to False" << endl;
}
//*/

PreviewArea::~PreviewArea()
{
}

QPixmap PreviewArea::previewItemAt(int location)
{
    QWidget *temp = layout->itemAt(location)->widget();
    QLabel *temp2  = new QLabel;
    temp2 = qobject_cast<QLabel *>(temp);
    QPixmap temp3 = QPixmap();
    temp3 = QPixmap(*temp2->pixmap());
    setPreviewItemEnabledAt(location, true);
    return temp3;
}

void PreviewArea::setPreviewItemAt(int location, QPixmap temp)
{
    temp.scaled(100, 100, Qt::KeepAspectRatio);
    QWidget *tempW = layout->itemAt(location)->widget();
    QLabel *temp2 = qobject_cast<QLabel *>(tempW);
    temp2->setScaledContents(true);
    temp2->setPixmap(temp);
    layout->insertWidget(location, temp2);
}

void PreviewArea::setPreviewItemEnabledAt(int location, bool enabled)
{
    enabled = true;
    int size = myLabels.size();

    myLabels[location]->setFrameShape(QFrame::Box);
    myLabels[location]->setLineWidth(3);
    if(location == 0)
        myLabels[size-1]->setFrameShape(QFrame::NoFrame);
    else
        myLabels[location-1]->setFrameShape(QFrame::NoFrame);

}

vector<int> PreviewArea::deletePreviewItems()
{    
    vector<int> toDelete;
    vector<int> empty;
    for(int i=myLabels.size()-1; i>=0; i--)
    {
        QWidget *foo = layout->itemAt(i)->widget();
        FImage *bar = new FImage(0);
        bar = qobject_cast<FImage*>(foo);
        if(bar->isSelected)
        {
            toDelete.push_back(i);
        }
    }

    if(myLabels.size() == toDelete.size())
    {
        QMessageBox msgBox;
        msgBox.setText("This will delete all photos from this collection");
        msgBox.setInformativeText("Do you want to delete selection?");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();

        switch (ret)
        {
           case QMessageBox::Ok:
                stopAnimation();
               // Save was clicked
               break;
           case QMessageBox::Cancel:
               // Cancel was clicked
               return empty;
               break;
           default:
               // should never be reached
               break;
         }
    }
    return toDelete;
}


void PreviewArea :: deleteImage (int index)
{
    stopAnimation();

    QLayoutItem* item;
    item = layout->takeAt(index);
    delete item->widget();
    delete item;

    myLabels.erase(myLabels.begin()+index);

    startAnimation(2500);
}

//Public slots
void PreviewArea :: startAnimation(int timerInterval)
{
    int temp = timerInterval;
    timer->start(4000);
}

void PreviewArea :: stopAnimation()
{
    timer->stop();
}

void PreviewArea :: timerTick(void)
{
    itemNum++;
    itemNum = itemNum % (myLabels.size());
    emit(animationChanged(itemNum));
}
