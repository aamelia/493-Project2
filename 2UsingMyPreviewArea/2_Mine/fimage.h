#ifndef FIMAGE_H
#define FIMAGE_H
#include <QtGui>
#include <QMainWindow>
#include <QWidget>
#include <QObject>

using namespace std;

class FImage : public QLabel
{
    Q_OBJECT

public:
    explicit FImage(int setIndex, QWidget *parent=0);

private:
    int index;

signals:
    
public slots:
    
};

#endif // FIMAGE_H
