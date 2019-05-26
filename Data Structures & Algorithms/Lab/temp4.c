#include <stdio.h>
#include <stdlib.h>

struct Student{
    char FName[20];
    char LName[20];
    char RollNo[15];
    float CGPA;
    struct Student *next;
};

struct Student* addStudent(struct Student* first_student){
    struct Student *newStudent = (void*)malloc(sizeof(struct Student));
    printf("\nEnter Student Details\nFirst Name : ");
    scanf("%s", newStudent->FName);
    printf("Last Name: ");
    scanf("%s", newStudent->LName);
    printf("Roll No: ");
    scanf("%s", newStudent->RollNo);
    printf("CGPA: ");
    scanf("%f", &(newStudent->CGPA));
    newStudent->next = NULL;
    if(first_student == NULL){
        *first_student = *newStudent;
    }
    return newStudent;
}

void linkStudents(struct Student *student1, struct Student *student2){
    student1->next = student2;
}

void showStudents(struct Student *student){
    if(student){
        printf("\nStudent Details:\nFirst Name: %s\nLast Name: %s\nRoll No: %s\nCGPA: %.2f\n-----------", student->FName, student->LName, student->RollNo, student->CGPA);
        showStudents(student->next);
    }
}

int main(){

struct Student *first_student = NULL;

    int noOfStudents;
    struct Student *end = NULL;
    printf("Enter No. of Student: ");
    scanf("%d", &noOfStudents);
    while(noOfStudents--){
        struct Student *new = addStudent(first_student);
        if(end == NULL){
            end = new;
        }
        else{
            linkStudents(end, new);
            end = new;
        }
    }
    // Printing all the students
    showStudents(first_student);

        
    // int choice;
	// do{
	// 	printf("Enter choice:\n1. Add a Student\n2. Link Student to another Student.\n3. Print Students\n0. Exit\n\t:  ");
	// 	scanf("%d", &choice);
	// 	system("cls");
    //  struct Student *student;
	// 	switch(choice){
	// 		case 1:
    //          student = addStudent();
	// 			break;
	// 		case 2:
    //         
    //             break;
	// 		case 3:
    //        
	// 			break;
	// 		case 4:
    //
	// 			break;
	// 	}
	// }while(choice != 0);
    // return 0;
}