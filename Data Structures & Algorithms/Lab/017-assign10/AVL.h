#ifndef AVL_H
#define AVL_H

struct tree
{
    int data;
    int height;
    struct tree *left, *right;
};
typedef struct tree Tree;

// Find Height
int Height(Tree *Node);

// Find Left-Heavy, Right-Heavy or Balanced 
int Balance(Tree *Node);

// Get Next Element in BST
Tree* GetNextElement(Tree* Node);

// Create a New Node
Tree* CreateNode(int data);

// Left Rotation
void RotateLL(Tree **Node);

// Right Rotation
void RotateRR(Tree **Node);

// Left-Right Rotation
void RotateLR(Tree **Node);

// Right-Left Rotation
void RotateRL(Tree **Node);

// Insert a new Element
Tree* Insert(Tree *Node, int data);

// Find an Element
int Find(Tree *Node, int data);

// Delete an Element
Tree* Delete(Tree *Node, int data);

void PrintInOrder(Tree *Node);
void PrintPreOrder(Tree *Node);
void PrintPostOrder(Tree *Node);

#endif