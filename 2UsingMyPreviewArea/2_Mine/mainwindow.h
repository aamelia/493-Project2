#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "flickrcollector.h"
#include "imagecollector.h"
#include "previewarea.h"
#include "deletecollectioncommand.h"

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
  void createActions();
  void createUndoView();
  void deleteCollection();
  void deletePhoto();

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
  QAction *deletePhotoAction;
  QAction *deleteCollectionAction;
  QUndoStack *undoStack;
  QUndoView *undoView;

  vector<QStringList> allCollections;
  vector<FImage> allCollectionsImages;

signals:
  void replaceBottom();
};

#endif // MAINWINDOW_H
