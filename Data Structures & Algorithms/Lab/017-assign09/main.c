// Ashutosh Chauhan
// Roll No- S20180010017

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BST.h"

#ifndef TOTAL_STUDENTS
    #define TOTAL_STUDENTS 25
#endif




int main(){
    // Student List
    Student* List = NULL;
    StudentBST* BST = NULL;
    int choice;
	do{
        int Roll;
		printf("\nEnter choice:\n1. Add A New Student \n2. Find a Student (BST) \n3. Update a Student \n4. List all the Students\n5. View Students in Sorted (InOrder) \n6. View Students in BST (PreOrder) \n7. View Students in BST (PostOrder) \n8. Delete a Student \n9. Pretty-Print BST \n0. Exit\n\t:  ");
		scanf("%d", &choice);
		system("clear");
		switch(choice){
			case 1:
                List = AddStudent(List, &BST);
                break;
            case 2:
                printf("Enter Student Roll No: ");
                scanf("%d", &Roll);
                PrintStudentDetails(FindStudentByRollNo(Roll, BST));
				break;
            case 3:
                printf("Enter Student Roll No: ");
                scanf("%d", &Roll);
                List = UpdateStudentByRollNo(Roll, List, &BST);
			case 4:
                PrintAll(List);
                break;
			case 5:
                PrintBstInOrder(BST);
                break;
			case 6:
                PrintBstPreOrder(BST);
                break;
			case 7:
                PrintBstPostOrder(BST);
                break;
			case 8:
                printf("Enter the Roll No of the Student: ");
                scanf("%d", &Roll);
                List = DeleteStudentByRollNo(Roll, List, &BST);
				break;
            case 9:
                PrettyPrint(BST, 0);
                break;
		}
	}while(choice != 0);
    return 0;
}