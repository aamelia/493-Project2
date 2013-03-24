#include "mainwindow.h"
#include <QtGui>
#include <QMainWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    photoCounter=0;
    this->setWindowTitle("Amelia Atkinson - Project 1");
    collector = new FlickrCollector(parent);
    leftPanel = new QListWidget;
    menuBar = new QMenuBar();
    imageWidget = new QWidget;
    collector = new FlickrCollector(parent);
    connect(collector, SIGNAL(ready()), this, SLOT(flickrCallback()));
    image = new ImageCollector();
    connect(image, SIGNAL(pixmapAvailable(QPixmap)), this, SLOT(processDownloadedPics(QPixmap)));
    currentCollection=0;
    numCollections=0;

    QHBoxLayout *imgLayout = new QHBoxLayout;
    mainImage = new QLabel;
    mainImage->setScaledContents(true);
    mainImage->setMaximumSize(375,375);

    //mainImage->setSizePolicy(Qt::KeepAspectRatioByExpanding, Qt::KeepAspectRatioByExpanding);
    //mainImage->setSizePolicy()
    //mainImage->setSizePolicy(Qt::PreferredSize, Qt::PreferredSize);
    imgLayout->addWidget(mainImage);
    imageWidget->setLayout(imgLayout);

    //imageWidget->setSizePolicy(QSizePolicy::Expanding);

    QVBoxLayout *leftPanelLayout = new QVBoxLayout();
    leftPanelLayout->addWidget(leftPanel);
    leftPanelContainer = new QWidget();
    leftPanelContainer->setMinimumWidth(150);
    leftPanelContainer->setMaximumWidth(200);
    leftPanelContainer->setLayout(leftPanelLayout);

    //Set up the bottom PreviewArea
    bottom = new PreviewArea();
    QVBoxLayout *anotherLayout = new QVBoxLayout();
    anotherLayout->addWidget(bottom);
    bottomContainer = new QWidget();
    bottomContainer->setLayout(anotherLayout);
    bottomContainer->setFixedHeight(160);


    //Building the layout of the window
    QSplitter *splitter1 = new QSplitter(Qt::Horizontal, this);
    splitter1->addWidget(leftPanelContainer);
    splitter1->addWidget(imageWidget);
    splitter1->setOpaqueResize(true);
    splitter1->setChildrenCollapsible(true);
    QList<int> tempList;
    tempList.insert(0, 500);
    tempList.insert(0, 200);
    splitter1->setSizes(tempList);
    //mainWindow size policy to prefered

    QSplitter *splitter2 = new QSplitter(Qt::Vertical, this);
    splitter2->addWidget(splitter1);
    splitter2->addWidget(bottomContainer);

    setCentralWidget(splitter2);
    createFlickr();
    createMenus();
    this->setMenuBar(menuBar);
}

MainWindow::~MainWindow(){}

void MainWindow::quit()
{
  QApplication::quit();
}

void MainWindow::resetCollection(int collectionNumber)
{
    urlList = allCollections[collectionNumber];
    int size = urlList.size();
    QString url;
    for(int i=0; i<size; i++)
    {
        url = urlList.at(i);
        image->loadImage(url);
    }
}

void MainWindow::flickrCallback(void)
{
    urlList = collector->list();
    if(urlList.size()==0)
    {
        createFlickr();
        cout << "something hacky" << endl;
    }
    else
    {
        allCollections.push_back(urlList);

        QListWidgetItem *collectionItem = new QListWidgetItem();
        collectionItem->setFlags(collectionItem->flags() | Qt::ItemIsEditable);
        collectionItem->setText(collector->collectionName());
        leftPanel->addItem(collectionItem);

        QString url;
        connect(bottom, SIGNAL(animationChanged(int)), this, SLOT(resetMainImage(int)));
        int size = urlList.size();
        for(int i=0; i<size; i++)
        {
            url = urlList.at(i);
            image->loadImage(url);
        }
    }
    currentCollection = leftPanel->count()-1;
}
void MainWindow::resetMainImage(int location)
{
    mainImage->setPixmap(bottom->previewItemAt(location));
}

void MainWindow::processDownloadedPics(QPixmap temp)
{
    bottom->setPreviewItemAt(photoCounter, temp);
    photoCounter++;
    if(photoCounter == 10)
        photoCounter = 0;
}

void MainWindow::createFlickr(void)
{
    collector->execute();
    numCollections++;
}

void MainWindow::createMenus()
{
    QMenu *fileMenu = menuBar->addMenu("File");
    QAction *temp;
    temp = fileMenu->addAction("Exit");
    connect(temp,SIGNAL(triggered()), this, SLOT(quit()));
    temp->setEnabled(true);

    temp = fileMenu->addAction("Open");
    temp->setEnabled(false);
    temp = fileMenu->addAction("Save");
    temp->setEnabled(false);
    temp = fileMenu->addAction("Save As");
    temp->setEnabled(false);

    QMenu *editMenu = menuBar->addMenu("Edit");
    temp = editMenu->addAction("Cut");
    temp->setEnabled(false);
    temp = editMenu->addAction("Copy");
    temp->setEnabled(false);
    temp = editMenu->addAction("Paste");
    temp->setEnabled(false);

    QMenu *collectionMenu = menuBar->addMenu("Collection");
    temp = collectionMenu->addAction("New Collection");
    temp->setEnabled(true);
    connect(temp,SIGNAL(triggered()), this, SLOT(createFlickr()));
    temp = collectionMenu->addAction("New Collection By Tags");
    temp->setEnabled(false);
    temp = collectionMenu->addAction("Play Collection");
    connect(temp, SIGNAL(triggered()), this, SLOT(mainStartAnimation()));
    temp->setEnabled(true);
    temp = collectionMenu->addAction("Delete Collection");
    temp->setEnabled(false);
    temp = collectionMenu->addAction("Delete Items in Collection");
    temp->setEnabled(false);

    QMenu *toolsMenu = menuBar->addMenu("Tools");
    temp = toolsMenu->addAction("Play Selected Collections");
    temp->setEnabled(false);
    temp = toolsMenu->addAction("Pause Play");
    connect(temp, SIGNAL(triggered()), bottom, SLOT(stopAnimation()));
    temp->setEnabled(true);
    temp = toolsMenu->addAction("Set Play Interval");
    temp->setEnabled(false);
}

void MainWindow::mainStartAnimation()
{
    if( leftPanel->currentRow() != -1)
    {
        if(currentCollection != leftPanel->currentRow())
        {
            resetCollection(leftPanel->currentRow());
            currentCollection = leftPanel->currentRow();
        }
    }

    bottom->startAnimation(leftPanel->currentRow());
}

