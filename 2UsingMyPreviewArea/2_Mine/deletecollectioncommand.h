#ifndef DELETECOLLECTIONCOMMAND_H
#define DELETECOLLECTIONCOMMAND_H

class DeleteCollectionCommand : public QUndoCommand
{
 public:
     DeleteCollectionCommand(vector<QStringList> allCollectionsInput, QUndoCommand *parent = 0);

     void undo();
     void redo();

 private:
     QStringList *currentCollection;
     vector<QStringList> allCollections;
 };

#endif // DELETECOLLECTIONCOMMAND_H
