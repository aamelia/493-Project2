#ifndef PREVIEWAREA_H
#define PREVIEWAREA_H
#include <QtGui>
#include <QMainWindow>
#include <QWidget>
#include "fimage.h"


using namespace std;

class PreviewArea : public QScrollArea
{
    Q_OBJECT

private:
    QScrollArea *scrollArea;
    QWidget *container;
    QHBoxLayout *layout;
    QTimer *timer;
    int itemNum;
    int timerInterval;
    vector<FImage *> myLabels;

public:
    PreviewArea(int size=10, QWidget *parent=0);
    ~PreviewArea();
    QPixmap previewItemAt(int);
    void setPreviewItemAt(int, QPixmap);
    void setPreviewItemEnabledAt(int, bool);
    vector<int> deletePreviewItems();
    FImage fImageAt(int location);

public slots:
    void startAnimation(int timerInterval);
    void stopAnimation();
    void timerTick(void);
    void resetImages(int newSize);

signals:
    void animationChanged(int);
    void previewItemChanged(int);
    void previewItemSelected(int);

};

#endif // PREVIEWAREA_H
