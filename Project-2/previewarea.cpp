#include "previewarea.h"
#include "fimage.h"
#include <QtGui>

#include <iostream>
#include <string>

using namespace std;

#include <stdio.h>

static const int MAX_PREVIEW = 10;
static const int DEFAULT_INTERVAL = 4000;
static const char *HIGHLIGHT_STYLE = "border: 2px solid blue";
static const char *NORMAL_STYLE = "border: 1px solid grey";
static const char *HIDING_STYLE =  "border: none";
static const int SPACING = 2;

PreviewArea::PreviewArea(int size_incoming, QWidget *parent)
  : QScrollArea(parent)
{
  FImage *label;
  QAction *action;
  currentImageLoc = 0;
  heldTimerInterval = 0;

  // a little housekeeping
  if (size_incoming <= MAX_PREVIEW)
    size = size_incoming;
  else
    size = MAX_PREVIEW;

  // lay 'er out
  hbox = new QWidget();
  QHBoxLayout *hboxLayout = new QHBoxLayout();
  hboxLayout->setSpacing(SPACING);
  hboxLayout->setContentsMargins(0,SPACING,0,SPACING);
  hboxLayout->insertSpacing(0,SPACING);
  imageLabelList.clear();
  for (int i=0;i<size;i++)
    {
      label = new FImage("loading...",i); //**remove for old
      //label = new QLabel("loading..."); //**remove for new
      imageLabelList.append(label);
      action = new QAction(label);
      label->addAction(action);
      label->setContentsMargins(SPACING,SPACING,SPACING,SPACING);
      label->setFixedSize(110,110);
      label->setAlignment(Qt::AlignCenter);
      label->setStyleSheet(NORMAL_STYLE);
      hboxLayout->addWidget(label);
      connect(label,SIGNAL(selected(int)),
          this,SLOT(previewItemTriggered(int)));
    }
  hboxLayout->addSpacing(SPACING);
  hbox->setLayout(hboxLayout);
  this->setWidget(hbox);
  this->setWidgetResizable(true);

  // set up the timer and start it
  timerInterval = DEFAULT_INTERVAL;
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(timerTick()));
  timer->start(timerInterval);
}


// for loading/starting a new collection
void PreviewArea::reinitialize()
{
  imageList.clear();
  if (currentImageLoc >= 0)
    imageLabelList.at(currentImageLoc)->setStyleSheet(NORMAL_STYLE);
  currentImageLoc = -1; // gets incremented below
  // start off on the first one
  imageLabelList.at(0)->setStyleSheet(HIGHLIGHT_STYLE);
}


// animation method
void PreviewArea::timerTick(void)
{
  if (imageList.size() < 3) // arbitrary threshold on when to start
     return;
  if (heldTimerInterval != 0) // first timer trigger on new annimation
    { //  restart immediately since user's been watching the current image
      timerInterval = heldTimerInterval; // move to requested speed
      timer->setInterval(timerInterval);
      heldTimerInterval = 0;
    }
  if (currentImageLoc+1 > imageLabelList.size())
    currentImageLoc = 0;
  if (currentImageLoc >= 0) // when beginning an animation, don't do this
    imageLabelList.at(currentImageLoc)->setStyleSheet(NORMAL_STYLE);

  /*if (imageList.size() == 0)
    currentImageLoc = 0;
    else */
  currentImageLoc = (++currentImageLoc)%imageList.size();
  imageLabelList.at(currentImageLoc)->setStyleSheet(HIGHLIGHT_STYLE);
  // emit a signal with the new location for whatever the app wants to do
  emit animationChanged(currentImageLoc);
}

void PreviewArea::previewItemTriggered(int)
{
  cout << "slot not implemented yet"<<endl;
}

void PreviewArea::setPreviewItemAt(int loc, QPixmap pixmap)
{
  // a little housekeeping
  if (loc >= MAX_PREVIEW || loc < 0)
    return;
  if (loc >= imageLabelList.size())
      return; // confused, so leave

  // get a scaled down pixmap and install it
  QPixmap pixmap2 = pixmap.scaled(100, 100, Qt::KeepAspectRatio);
  FImage *label = imageLabelList.at(loc); //**remove for old
  //QLabel *label = imageLabelList.at(loc); //**remove for new
  imageList.append(pixmap);
  label->setPixmap(pixmap2);
  label->setContentsMargins(0,0,0,0);
  label->setAlignment(Qt::AlignCenter);
  emit previewItemChanged(loc);
}

void PreviewArea::deletePreviewItemAt(int loc)
{
  cout << "deleting image " << loc <<endl;
}

// unfortunately this can't be used for selecting
void PreviewArea::setPreviewItemEnabledAt(int loc,bool value)
{
  imageLabelList.at(loc)->setEnabled(value);
}


QPixmap PreviewArea::previewItemAt(int loc)
{
  return imageList.at(loc);
}

/* animation methods */

void PreviewArea::startAnimation(int timerInterval_incoming)
{
  if (timerInterval_incoming <= 100) // really less than a 1/10 of a sec?
    timerInterval = DEFAULT_INTERVAL;
  else
    timerInterval = timerInterval_incoming;
  timer->start(timerInterval);
  if (currentImageLoc < 0) //fencepost problem
    emit animationChanged(0); //show the image immediately
  else
    emit animationChanged(currentImageLoc);

}

void PreviewArea::stopAnimation()
{
  if (timer->isActive())
    timer->stop();
}

void PreviewArea::pauseAnimation()
{
  if (timer->isActive())
    timer->stop();
}

void PreviewArea::restartAnimation()
{
  //  restart immediately since user's been watching the current image anyways
  if (timerInterval > 100)
    {
      heldTimerInterval = timerInterval;
      timerInterval = 100;
      timer->start(timerInterval);
    }
}


PreviewArea::~PreviewArea()
{
  delete hbox; // will delete all of its children and layouts
  delete timer;
}
