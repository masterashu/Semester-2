// Ashutosh Chauhan
// Roll No- S20180010017

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef MAX_STUDENTS
    #define MAX_STUDENTS 50
#endif

struct student
{
    char Name[40];
    int RollNo;
    struct student *next;
};
typedef struct student Student;
Student *g_student_index[MAX_STUDENTS];
Student *g_Students_List_Head = NULL;

void SetStudentsIndex(){
    for(int i = 0; i < MAX_STUDENTS; i++){
        g_student_index[i] == NULL;
    }
}

void add_to_index(Student* aStudent){
    for(int i = 0; i < MAX_STUDENTS; i++){
        if(g_student_index[i] == NULL){
            g_student_index[i] = aStudent;
            return;
        }
    }
    printf("!!! No. of Students exceeds MAX_STUDENT !!!\n");
}

void delete_from_index(Student* aStudent){
    int flag = -1;
    for(int i = 0; i < MAX_STUDENTS; i++){
        if(g_student_index[i] == aStudent){
            g_student_index[i] == NULL;
            flag = i;
        }
    }
    for(int i = flag; i < MAX_STUDENTS-1; i++){
        g_student_index[i] = g_student_index[i+1];
    }
    if(flag == -1)
        printf("!!! Student not Found !!!");
}

void add(Student* NewStudent){
    if(g_Students_List_Head == NULL){
        g_Students_List_Head = NewStudent;
    }
    else{
        Student *temp = g_Students_List_Head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = NewStudent;
    }
}

Student* create(){
    Student *NewStudent = (void*)malloc(sizeof(Student));
    printf("\nEnter Student Details\nName : ");
    scanf("%s", NewStudent->Name);
    printf("Roll No: ");
    scanf("%d", &(NewStudent->RollNo));
    NewStudent->next = NULL;
    add_to_index(NewStudent);
    return NewStudent;
}

void print(Student *aStudent){
    printf("\nStudent Details\nName : %s", aStudent->Name);
    printf("\nRoll No: %d", aStudent->RollNo);
}

void print_from(Student *aStudent){
    if(aStudent != NULL){
        print(aStudent);
        print_from(aStudent->next);
    }
}

void print_all(){
    Student *head = g_Students_List_Head;
    if(head == NULL){
        printf("No Student Details Available!\n");
    }
    else{
        print_from(head);
    }
}

// ??
void update(int index, Student* nStudent){
    Student* temp = g_Students_List_Head;
    while(--index > 0){
        temp = temp->next;
        if(temp == NULL){
            printf("!!! Error, non-existing index !!!\n");
            return;
        }
    }
    if(temp->next != NULL){
        // replacing aStudent with nStudent
        // making sure no link is broken
        // ... temp -> aStudent -> temp2 ...
        // ... temp -> nStudent -> temp2 ...
        Student *temp2 = temp->next->next;
        Student *aStudent = temp->next;
        temp->next = nStudent;
        nStudent->next = temp2;
        delete_from_index(aStudent);
        free(aStudent);
    }
    else{
        temp->next = nStudent;
        nStudent->next = NULL;
    }
}

void insert(int index, Student* aStudent){
    Student* temp = g_Students_List_Head;
    // If the head is already Null
    if(temp == NULL){
        g_Students_List_Head = aStudent;
        return;
    }
    // If inserting at Head Position
    // head -> temp2 ...
    // aStudent -> head -> temp2 ...
    if(index == 0){
        aStudent->next = g_Students_List_Head;
        g_Students_List_Head = aStudent;
        return;
    }
    while(--index > 0 && temp->next != NULL){
        temp = temp->next;
    }
    // inserting aStudent
    // making sure no link is broken
    // ... temp -> temp2 ...
    // ... temp -> aStudent -> temp2 ...
    Student *temp2 = temp->next;
    temp->next = aStudent;
    aStudent->next = temp2;
}

void delete_student(int index){
    Student *temp = g_Students_List_Head;
    while(index--){
        temp = temp->next;
        if(temp == NULL){
            printf("!!! Error, non-existing index !!!\n");
            return;
        }
    }
    // deleting aStudent
    // making sure no link is broken
    // ... temp -> aStudent -> temp2 ...
    // ... temp -> temp2 ...
    Student *temp2 = temp->next;
    temp->next = temp2->next;
    delete_from_index(temp2);
    free(temp2);
}

Student* get(int index){
    Student *temp = g_Students_List_Head;
    while(index--){
        temp = temp->next;
        if(temp == NULL){
            printf("!!! Error, non-existing index !!!\n");
            return NULL;
        }
    }
    return temp;
}

void update_index(){
    for(int i = 0; i < MAX_STUDENTS; i++){
        for(int j = 0; j < MAX_STUDENTS - i - 1; j++){
            if(g_student_index[j] == NULL && g_student_index[j+1] != NULL){
                Student* temp = g_student_index[j+1];
                g_student_index[j+1] = g_student_index[j];
                g_student_index[j] = temp;
            }
            if(g_student_index[j] != NULL && g_student_index[j+1] != NULL){
                if(g_student_index[j+1]->RollNo < g_student_index[j]->RollNo){
                    Student* temp = g_student_index[j+1];
                    g_student_index[j+1] = g_student_index[j];
                    g_student_index[j] = temp;
                }
            }
        }
    }
}

int search(int RollNo){
    int begin = 0, end = MAX_STUDENTS - 1;
    while(begin < end){
        int mid = (begin + end)/2;
        if(g_student_index[mid] == NULL){
            end = mid-1;
            continue;
        }
        if(g_student_index[mid]->RollNo == RollNo){
            print(g_student_index[mid]);
            return mid;
        }
        if(g_student_index[mid]->RollNo > RollNo){
            begin = mid;
        }
        else{
            end = mid - 1;
        }
    }
    printf("! Student Roll No. not Found !\n");
    return -1;
}

void Print_by_index(){
    update_index();
    for(int i = 0; i < MAX_STUDENTS; i++){
        if(g_student_index[i] == NULL){
            break;
        }
        else{
            print(g_student_index[i]);
        }
    }
}


int main(){
    SetStudentsIndex();
    int choice;
	do{
		printf("\nEnter choice:\n1. Create a new student\n2. Print all students\n3. Update a student\n4. Insert a student\n5. Delete a student\n6. Update index array\n7. Search by roll no\n8. Print by index array\n0. Exit\n\t:  ");
		scanf("%d", &choice);
		system("clear");
		switch(choice){
			case 1:
                printf("Creating Student\n");
                Student* NewStudent = create();
                add(NewStudent);
				break;
			case 2:
                print_all();
                break;
			case 3:
                printf("Enter index of Student: ");
                int updateIndex;
                scanf("%d", &updateIndex);
                Student* newStudent = create();
                update(updateIndex, newStudent);
				break;
			case 4:
                printf("Enter position to be inserted: ");
                int index;
                scanf("%d", &index);
                Student *aStudent = create();
                insert(index, aStudent);
				break;
            case 5:
                printf("Deletion of element: \n1. Use index\n2. Use Roll No.\n");
                int DelChoice;
                scanf("%d", &DelChoice);
                if(DelChoice == 1){
                    printf("Enter index to delete: ");
                    int index;
                    scanf("%d", &index);
                    update_index();
                    delete_student(index);
                }
                if(DelChoice == 2){
                    printf("Enter Roll No. to delete: ");
                    int RollNo;
                    scanf("%d", &RollNo);
                    update_index();
                    delete_student(search(RollNo));
                    update_index();
                }
                break;
            case 6:
                break;
            case 7:
                printf("Enter Roll No. to Search: ");
                int RollNo;
                scanf("%d", &RollNo);
                print(g_student_index[search(RollNo)]);
                break;
            case 8:
                Print_by_index();
                break;
		}
	}while(choice != 0);
    return 0;
}