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
    }

    container->setLayout(layout);
    container->setMaximumHeight(110);
    this->setWidget(container);
}

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
    int size = myLabels.size();
    int numSelected = 1;
    if(myLabels.size() == 1)
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
               // Save was clicked
               break;
           case QMessageBox::Cancel:
               // Cancel was clicked
               return toDelete;
               break;
           default:
               // should never be reached
               break;
         }
    }
        //myLabels.erase(myLabels.begin());
        int newSize = size-numSelected;
        toDelete.push_back(newSize);
        cout << "The new size of myLabels is:" << newSize << endl;

        //set up toDelete
        toDelete.push_back(0);
        return toDelete;
}

//Public slots
void PreviewArea :: resetImages (int newSize)
{
    stopAnimation();

    //clear hboxlayout layout using layout.takeAt()
    QLayoutItem* item;
    while((item = layout->takeAt(0)) != NULL)
    {
        delete item->widget();
        delete item;
    }

    //clear myLabels
    myLabels.clear();

    //reset the images
    cout << "reset the images" << endl;
    cout << "The new size is: " << newSize << endl;

    /*
    FImage *temp;
    for(int i=0; i<newSize; i++)
    {
        temp = new FImage(i);
        temp->setFixedSize(100,100);
        temp->setScaledContents(true);
        layout->addWidget(temp);
        myLabels.push_back(temp);
    }
    */
    //startAnimation(2500);
}

void PreviewArea :: startAnimation(int timerInterval)
{
    int temp = timerInterval;
    timer->start(2000);
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
