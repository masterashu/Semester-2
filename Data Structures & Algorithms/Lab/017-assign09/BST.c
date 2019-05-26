#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

StudentBST* CreateBST(Student* newStudent){
    StudentBST* newNode = (void*)malloc(sizeof(StudentBST));
    newNode->StudentPtr = newStudent;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

StudentBST* AddStudentBST(StudentBST *newStudentNode, StudentBST *BST){
    if(BST == NULL){
        return newStudentNode;
    }
    else{
        if(newStudentNode->StudentPtr->RollNo < BST->StudentPtr->RollNo){
            BST->left = AddStudentBST(newStudentNode, BST->left);
        }
        else{
            BST->right = AddStudentBST(newStudentNode, BST->right);
        }
    }
}

StudentBST* DeleteStudentBST(Student *aStudent, StudentBST *BST){
    if(BST == NULL){
        return NULL;
    }
    if(BST->StudentPtr == aStudent){
        if(BST->left == NULL && BST->right == NULL){
            // Deleting a Leaf Node
            free(BST);
            return NULL;
        }
        // Deleting Node With a Single Child
        if(BST->left == NULL){
            StudentBST *tmp = BST->right;
            free(BST);
            return tmp;
        }
        if(BST->right == NULL){
            StudentBST *tmp = BST->left;
            free(BST);
            return tmp;
        }
        // Deleting Node with both the child
        // Find Minimum of Right-Subtree
        StudentBST *tmp = BST->right;
        while(tmp->left != NULL){
            tmp = tmp->left;
        }
        Student* aStudentPtr = tmp->StudentPtr;
        BST->StudentPtr = aStudentPtr;
        BST->right = DeleteStudentBST(aStudentPtr,BST->right);
        return BST;
    }
    if(aStudent->RollNo < BST->StudentPtr->RollNo){
        BST->left = DeleteStudentBST(aStudent, BST->left);
    }
    else{
        BST->right = DeleteStudentBST(aStudent, BST->right);
    }
    return BST;
}

void PrintBstInOrder(StudentBST *BST){
    if(BST == NULL){
        return;
    }
    PrintBstInOrder(BST->left);
    PrintStudentDetails(BST->StudentPtr);
    PrintBstInOrder(BST->right);
}

void PrintBstPreOrder(StudentBST *BST){
    if(BST == NULL){
        return;
    }
    PrintStudentDetails(BST->StudentPtr);
    PrintBstPreOrder(BST->left);
    PrintBstPreOrder(BST->right);
}

void PrintBstPostOrder(StudentBST *BST){
    if(BST == NULL){
        return;
    }
    PrintBstPostOrder(BST->left);
    PrintBstPostOrder(BST->right);
    PrintStudentDetails(BST->StudentPtr);
}

Student* GetStudent(int Roll, Student* List){
    while(List != NULL){
        if(List->RollNo == Roll){
            return List;
        }
        List = List->next;
    }
    return NULL;
}

Student* CreateStudent(){
    Student *newStudent = (void*)malloc(sizeof(Student));
    printf("\nEnter details of Student:\n");
    printf("Student Name: ");
    scanf("%s", newStudent->Name);
    printf("Roll No: ");
    scanf("%d", &(newStudent->RollNo));
    printf("CGPA: ");
    scanf("%f", &(newStudent->CGPA));
    newStudent->next = NULL;
    return newStudent;
}

Student* AddStudent(Student *List, StudentBST **BST){
    Student *newStudent = CreateStudent();
    StudentBST *newNode = CreateBST(newStudent);
    *BST = AddStudentBST(newNode, *BST);
    if(List == NULL){
        return newStudent;
    }
    else{
        Student* tmp = List;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = newStudent;
        return List;
    }
}

Student* UpdateStudentByRollNo(int Roll, Student *List, StudentBST **BST){
    Student *uStudent = GetStudent(Roll, List);
    Student *tmp = List;
    if(uStudent == NULL){
        return List;
    }
    // Found at the Begining
    if(tmp == uStudent){
        tmp = tmp->next;
        *BST = DeleteStudentBST(uStudent, *BST);
        free(uStudent);
        Student *newStudent = CreateStudent();
        newStudent->next = tmp;
        StudentBST *newStudentNode = CreateBST(newStudent);
        *BST = AddStudentBST(newStudentNode, *BST);
        return newStudent;
    }
    else{
        while(tmp->next != uStudent){
            tmp = tmp->next;
        }
        *BST = DeleteStudentBST(uStudent, *BST);
        tmp->next = uStudent->next;
        free(uStudent);
        Student *newStudent = CreateStudent();
        newStudent->next = tmp->next;
        tmp->next = newStudent;
        StudentBST *newStudentNode = CreateBST(newStudent);
        *BST = AddStudentBST(newStudentNode, *BST);
        return List;
    }
}

Student* DeleteStudentByRollNo(int Roll, Student *List, StudentBST **BST){
    Student* dStudent = GetStudent(Roll, List);
    if(dStudent == NULL){
        printf("NOT FOUND!!!\n");
        return List;
    }
    // Found at the Begining
    if(List == dStudent){
        List = List->next;
        *BST = DeleteStudentBST(dStudent, *BST);
        free(dStudent);
        return List;
    }
    else{
        Student* tmp = List;
        while(tmp->next != dStudent){
            tmp = tmp->next;
        }
        // Removing dStudent from the Chain (Linked List)
        *BST = DeleteStudentBST(dStudent, *BST);
        tmp->next = dStudent->next;
        free(dStudent);
        return List;
    }
}

Student* FindStudentByRollNo(int Roll, StudentBST *BST){
    if(BST == NULL){
        return NULL;
    }
    if(BST->StudentPtr->RollNo == Roll){
        return BST->StudentPtr;
    }
    if(Roll < BST->StudentPtr->RollNo){
        return FindStudentByRollNo(Roll, BST->left);
    }
    else{
        return FindStudentByRollNo(Roll, BST->right);
    }
}

void PrintStudentDetails(Student *aStudent){
    printf("\nStudent Details:\nName: %s\nRoll No: %d\nCGPA: %.1f\n-----------",aStudent->Name ,aStudent->RollNo ,aStudent->CGPA );
}

void PrintAll(Student *List){
    if(List != NULL){
        PrintStudentDetails(List);
        PrintAll(List->next);
    }
}

void PrettyPrint(StudentBST *BST, int count){
    if(BST == NULL){
        return;
    }
    count += 1;
    PrettyPrint(BST->right, count);

    printf("\n");
    for(int i = 1; i < count; i++){
        printf("            ");
    }
    if(count > 1)
    printf("|------------");
    printf("[%s   %d] ->", BST->StudentPtr->Name, BST->StudentPtr->RollNo);
    PrettyPrint(BST->left, count);

}


