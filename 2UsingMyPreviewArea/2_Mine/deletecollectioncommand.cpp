#include "deletecollectioncommand.h"

DeleteCollectionCommand::DeleteCollectionCommand(vector<QStringList> allCollectionsInput, QUndoCommand *parent)
     : QUndoCommand(parent)
 {
     allCollections = allCollectionsInput;

     QList<QGraphicsItem *> list = myGraphicsScene->selectedItems();
     list.first()->setSelected(false);
     myDiagramItem = static_cast<DiagramItem *>(list.first());
     setText(QObject::tr("Delete %1")
         .arg(createCommandString(myDiagramItem, myDiagramItem->pos())));
 }

void DeleteCommand::undo()
 {
     allCollections.push_back(currentCollection);
     allCollections->update();
 }

void DeleteCommand::redo()
 {
     myGraphicsScene->removeItem(myDiagramItem);
 }
