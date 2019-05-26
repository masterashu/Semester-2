#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

int main(){
    Tree* AvlTree = NULL;
    int choice;
	do{
		printf("\nEnter choice:\n1. Insert a new Element\n2. Find a Number\n3. Delete a number\n4. Print Numbers (InOrder) \n5. Print Number (PreOrder)\n6. Print Number (PostOrder)\n0. Exit\n\t:  ");
		scanf("%d", &choice);
		system("clear");
        int data;
		switch(choice){
			case 1:
                printf("Enter Number to Insert: ");
                scanf("%d", &data);
                AvlTree = Insert(AvlTree, data);
				break;
			case 2:
                printf("Enter Number to Find: ");
                scanf("%d", &data);
                if(Find(AvlTree, data) == 1){
                    printf("Number Exists!\n");
                }
                else{
                    printf("Number Doesn't Exist!");
                }
                break;
			case 3:
                printf("Enter Number to Delete: ");
                scanf("%d", &data);
                AvlTree = Delete(AvlTree, data);
				break;
			case 4:
                PrintInOrder(AvlTree);
				break;
            case 5:
                PrintPreOrder(AvlTree);
                break;
            case 6:
                PrintPostOrder(AvlTree);
                break;
		}
	}while(choice != 0);
    return 0;
}