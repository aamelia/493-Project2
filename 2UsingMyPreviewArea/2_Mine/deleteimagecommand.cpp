#include "deleteimagecommand.h"

DeleteImageCommand::DeleteImageCommand(vector<int> &toDeleteIn, PreviewArea &bottomIn,
                                       vector<QStringList> &allCollectionsIn,
                                       int currentCollectionIn)// QUndoCommand *parent)
{   
    bottom = new PreviewArea();

    toDelete = toDeleteIn;
    bottom = &bottomIn;
    allCollections = allCollectionsIn;
    currentCollection = currentCollectionIn;

    setText("Delete Selected Images");

    cout << "initializing deleteImageCommand" << endl;
}

//undo of deletion: reinsertion
void DeleteImageCommand::undo()
{

}

//does the deletion
void DeleteImageCommand::redo()
{
    toDelete = bottom->deletePreviewItems();
    for(unsigned int i=0; i<toDelete.size(); i++)
    {
        allCollections[currentCollection].removeAt(toDelete[i]);
        bottom->deleteImage(toDelete[i]);
    }
}
