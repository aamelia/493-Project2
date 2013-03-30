#ifndef DELETEIMAGECOMMAND_H
#define DELETEIMAGECOMMAND_H

#include <QtGui>
#include <QtNetwork>
#include <iostream>
#include <string>
#include "previewarea.h"
#include "fimage.h"

using namespace std;

class DeleteImageCommand : public QUndoCommand
{

public:
    DeleteImageCommand(vector<int> &toDeleteIn, PreviewArea &bottomIn,
                       vector<QStringList> &allCollectionsIn,
                       int currentCollectionIn);// QUndoCommand *parent);
    void undo();
    void redo();

    vector<int> toDelete;
    PreviewArea *bottom;
    vector<QStringList> allCollections;
    int currentCollection;
};

#endif // DELETEIMAGECOMMAND_H
