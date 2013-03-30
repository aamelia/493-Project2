#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "flickrcollector.h"
#include "imagecollector.h"
#include "previewarea.h"
#include "deleteimagecommand.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
  void quit(void);
  void flickrCallback(void);
  void createFlickr();
  void createMenus();
  void processDownloadedPics(QPixmap);
  void resetMainImage(int location);
  void mainStartAnimation();
  void resetCollection(int collectionNumber);
  void deleteCollection();
  void deleteSelection();

private:
  FlickrCollector *collector;
  QStringList urlList;
  QListWidget *leftPanel;
  QMenuBar *menuBar;
  QWidget *imageWidget;
  QWidget *leftPanelContainer;
  QWidget *bottomContainer;
  PreviewArea *bottom;
  QLabel *mainImage;
  ImageCollector *image;
  int currentCollection;
  int numCollections;
  int photoCounter;

  vector<QStringList> allCollections;
  vector<int> toDelete;

  QAction *deleteImageCommandAction;
  QUndoStack *undoStack;

signals:
  void replaceBottom();
  void deletedFromMain(int);
};

#endif // MAINWINDOW_H
