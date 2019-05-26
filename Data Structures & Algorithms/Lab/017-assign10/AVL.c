#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"
#define max(a,b) ((a>b)?(a):(b))

// Find height of a Subtree
int Height(Tree *Node){
    if(Node == NULL){
        return 0;
    }
    else{
        return Node->height;
    }
}

// Find Left-Heavy, Right-Heavy or Balanced 
int Balance(Tree *Node){
    if(Node == NULL){
        return 0;
    }
    else{
        return  Height(Node->left) - Height(Node->right);
    }
}

Tree* GetNextElement(Tree* Node){
    while(Node->left != NULL){
        Node = Node->left;
    }
    return Node;
}

// Create a New Node
Tree* CreateNode(int data){
    Tree* newNode = (void*)malloc(sizeof(Tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Left Rotation
/* 
 *       A               B
 *      / \            /   \
 *         B          A     C
 *        x \    =>  / x   / \
 *           C
 *          / \  
 */
void RotateLL(Tree **Node){
    Tree *A = *Node;
    Tree *B = A->right;
    Tree *x = B->left;

    A->right = x;
    B->left = A;

    A->height = max(Height(A->left),Height(A->right)) + 1;
    B->height = max(Height(B->left),Height(B->right)) + 1;

    *Node = B;
}

// Right Rotation
/* 
 *       A           B
 *      /  \        /  \
 *     B           C    A
 *    / x     =>  / \  x  \
 *   C
 *  / \
 */
void RotateRR(Tree **Node){
    Tree* A = *Node;
    Tree* B = A->left;
    Tree* x = B->right;

    A->left = x;
    B->right = A;

    A->height = max(Height(A->left),Height(A->right)) + 1;
    B->height = max(Height(B->left),Height(B->right)) + 1;

    *Node = B;
}

// Left-Right Rotation
/* 
 *       A               C
 *      / \             / \
 *     B               B   A
 *    / \    =>      / x   y \
 *       C
 *      x y  
 */
void RotateLR(Tree **Node){
    Tree *A = *Node;
    Tree *B = A->left;
    Tree *C = B->right;
    Tree *x = C->left;
    Tree *y = C->right;

    B->right = x;
    A->left = y;
    C->left = B;
    C->right = A;

    B->height = 1 + max(Height(B->left),Height(B->right));
    A->height = 1 + max(Height(A->left),Height(A->right));
    C->height = 1 + max(Height(C->left),Height(C->right));

    *Node = C;
}

// Right-Left Rotation
/* 
 *       A              C
 *      / \            / \
 *         B          A   B
 *        / \    =>  / x  y \
 *       C
 *      x y  
 */
void RotateRL(Tree **Node){
    Tree *A = *Node;
    Tree *B = A->right;
    Tree *C = B->left;
    Tree *x = C->left;
    Tree *y = C->right;

    A->right = x;
    B->left = y;
    C->left = A;
    C->right = B;

    B->height = 1 + max(Height(B->left),Height(B->right));
    A->height = 1 + max(Height(A->left),Height(A->right));
    C->height = 1 + max(Height(C->left),Height(C->right));

    *Node = C;
}

// Insert a new Element
Tree* Insert(Tree *Node, int data){

    if(Node == NULL){
        return CreateNode(data);
    }

    if(data < (Node)->data){
        Node->left = Insert(Node->left, data);
    }
    else if(data > Node->data){
        Node->right = Insert(Node->right, data);
    }
    // Update New Height of Inserted Node
    Node->height = 1 + max(Height(Node->left),Height(Node->right));
    // Checking is Tree is Still Balanced
    int balance = Balance(Node);
    if(balance > 1){    // Left Heavy
        if(data < Node->left->data){
            RotateRR(&Node);
        }
        else{
            RotateLR(&Node);
        }
    }
    else
    if(balance < -1){   // Right Heavy
        if(data > Node->right->data){
            RotateLL(&Node);
        }
        else{
            RotateRL(&Node);
        }
    }
    return Node;
}

// Find an Element
int Find(Tree *Node, int data){
    if(Node == NULL){
        return 0;
    }
    if(Node->data == data){
        return 1;
    }
    if(data < Node->data){
        return Find(Node->left, data);
    }
    else{
        return Find(Node->right, data);
    }
}

// Delete an Element
Tree* Delete(Tree *Node, int data){
    if(Node == NULL){
        return NULL;        // Not Found!
    }
    if(data < Node->data){  // Search in Left Subtree
        Node->left = Delete(Node->left, data);
    }
    if(data > Node->data){  // Search in Right Subtree
        Node->right = Delete(Node->right, data);
    }

    Tree *child = NULL;
    if(Node->data == data){ // Deleting the Current Node
        // Leaf Node
        if(Node->left == NULL && Node->right == NULL){
            free(Node);
            Node = NULL;
        }
        // Single Child
        if(Node->left == NULL){
            child = Node->right;
            *Node = *(Node->right);
            free(child);
        }
        else
        // Single Child
        if(Node->right == NULL){
            child = Node->left;
            *Node = *(Node->left);
            free(child);
        }
        // Two Childs
        else{
            Tree *tmp = GetNextElement(Node->right);
            Node->data = tmp->data;
            Node->right = Delete(Node->right, tmp->data);
        }
    }
    // If leaf Node is Deleted
    if(Node == NULL){
        return NULL;
    }
    // Otherwise
    Node->height = 1 + max(Height(Node->left),Height(Node->right));
    int balance = Balance(Node);
    if(balance > 1){        // Tree is Left Heavy
        if(Balance(Node->left) >= 0){   // If Left Subtree is Balanced or Left Heavy
            RotateRR(&Node);
        }
        else{
            RotateLR(&Node);
        }
    }
    if(balance < -1){       // Tree is Right Heavy
        if(Balance(Node->right) > 0){  // If Right Subtree is Left Heavy
            RotateRL(&Node);
        }
        else{
            RotateLL(&Node);
        }
    }
    return Node;
}

// Printing Function
void PrintInOrder(Tree *Node){
    if(Node != NULL){
        PrintInOrder(Node->left);
        printf("%d ", Node->data);
        PrintInOrder(Node->right);
    }
}

void PrintPreOrder(Tree *Node){
    if(Node != NULL){
        printf("%d ", Node->data);
        PrintPreOrder(Node->left);
        PrintPreOrder(Node->right);
    }
}

void PrintPostOrder(Tree *Node){
    if(Node != NULL){
        PrintPostOrder(Node->left);
        PrintPostOrder(Node->right);
        printf("%d ", Node->data);
    }
}
