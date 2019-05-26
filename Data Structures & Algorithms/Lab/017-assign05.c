// Ashutosh Chauhan
// Roll No- S20180010017

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef TOTAL_STUDENTS
    #define TOTAL_STUDENTS 5
#endif

struct student
{
    char Name[40];
    int RollNo;
    float CGPA;
    struct student *favorite;
};
typedef struct student Student;

// Global Array of Student Pointers
Student* g_students[TOTAL_STUDENTS];


void populate_student_details(){
    
    for(int i = 0; i < TOTAL_STUDENTS; i++){
        Student *newStudent = (void*)malloc(sizeof(Student));
        printf("\nEnter details of Student %d", i+1);
        printf("\nEnter Student Details\nName : ");
        scanf("%s", newStudent->Name);
        printf("Roll No: ");
        scanf("%d", &(newStudent->RollNo));
        printf("CGPA: ");
        scanf("%f", &(newStudent->CGPA));
        // Adding Student pointer to the Global Array
        g_students[i] = newStudent;
    }
}

int find_index(int RollSearch){
    for(int i = 0; i < TOTAL_STUDENTS; i++){
        if(g_students[i]->RollNo == RollSearch){
            return i;
        }
    }
    return -1;
}

void make_favorite_student(int Roll1, int Roll2){
    int index1 = find_index(Roll1);
    int index2 = find_index(Roll2);
    if(index1 == -1){
        printf("Student 1 doesn't Exist!\n");
        return;
    }
    if(index2 == -1){
        printf("Student 2 doesn't Exist!\n");
        return;
    }
    // Assigning Student2 as favorite of Student1
    g_students[index1]->favorite = g_students[index2];
}

void print_fav_chain(Student *sptr){
    // to break circular connection
    static int StudentCount = 0;
    if(StudentCount > TOTAL_STUDENTS){
        printf("Circular Connection Detected!\n");
        StudentCount = 0;
        return;
    }
    if(sptr){
        StudentCount++;
        printf("\nStudent Details:\nName: %s\nRoll No: %d\nCGPA: %.2f\n-----------",sptr->Name ,sptr->RollNo ,sptr->CGPA );
        print_fav_chain(sptr->favorite);
    }
}

void print_from_student(int Roll){
    int index = find_index(Roll);
    if(index == -1){
        printf("Roll No. Not Found");
        return;
    }
    print_fav_chain(g_students[index]);
}


int main(){
    int choice;
	do{
		printf("\nEnter choice:\n1. Populate Student Details \n2. Find index using Roll No.\n3. Make Student2 as favorite of Student1\n4. Print chain of Favorites\n0. Exit\n\t:  ");
		scanf("%d", &choice);
		system("clear");
		switch(choice){
			case 1:
                populate_student_details();
				break;
			case 2:
                printf("Enter Roll No. to be find: ");
                int Roll;
                scanf("%d", &Roll);
                int index = find_index(Roll);
                if(index == -1){
                    printf("Roll No. Not Found");
                    break;
                }
                printf("Index Position for Roll No %d is %d.\n", Roll, index);
                break;
			case 3:
                printf("Enter Roll No. of Student1: ");
                int Roll1,Roll2;
                scanf("%d", &Roll1);
                printf("Enter Roll No. of Student2: ");
                scanf("%d", &Roll2);
                make_favorite_student(Roll1,Roll2);
				break;
			case 4:
                printf("Enter the Roll No of the starting Student: ");
                int RollNo;
                scanf("%d", &RollNo);
                print_from_student(RollNo);
				break;
		}
	}while(choice != 0);
    return 0;
}