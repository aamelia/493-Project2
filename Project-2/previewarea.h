#ifndef PREVIEWAREA_H
#define PREVIEWAREA_H

#include <QtGui>
#include <QtNetwork>
#include "fimage.h"

class PreviewArea : public QScrollArea
{

  Q_OBJECT

public:
  PreviewArea(int size = 10, QWidget *parent = 0);
  ~PreviewArea();
  void reinitialize();
  QPixmap previewItemAt(int);
  void setPreviewItemAt(int,QPixmap);
  void setPreviewItemEnabledAt(int,bool);
  void deletePreviewItemAt(int);


 protected:
  QWidget *hbox;
  // QList<QLabel *> imageLabelList;
  QList<FImage *> imageLabelList;
  QList<QPixmap> imageList;
  int currentImageLoc;
  int size;
  QTimer *timer;
  int timerInterval;
  bool newAnimation;
  int heldTimerInterval;

 public slots:
  void startAnimation(int timerInterval);
  void stopAnimation();
  void timerTick(void);
  void pauseAnimation(void);
  void restartAnimation(void);
  void previewItemTriggered(int);

 signals:
  void animationChanged(int location);
  void previewItemChanged(int location);
  void previewItemSelected(int location);

};

#endif // PREVIEWAREA_H
