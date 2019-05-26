#include<stdio.h>
#include<stdlib.h>
struct Student
{
char name[100];
int rollnumber;
int cgpa;
struct Student *next;
};
typedef  struct Student student;
struct heap{
    int count;
    student* StudentPtr[1000];
};
typedef struct heap Heap;
student *list = NULL;
Heap myHeap = {0, NULL};



void print1()
{
student *temp;
temp=list;
if(temp==NULL)
{

    printf("00");
    return;
}
    while(temp!=NULL)
    {
        printf("%s %d %d \n",temp->name,temp->rollnumber,temp->cgpa);
        temp=temp->next;
    }
}

void printstudent(student * temp){

if(temp != NULL)
printf("%s %d %d \n",temp->name,temp->rollnumber,temp->cgpa);
}
student* create()
{
    student *new_student=(student *)malloc(sizeof(student));
    printf("Enter the details of student: ");
    scanf("%s %d %d",new_student->name,&(new_student->rollnumber),&(new_student->cgpa));
    new_student->next=NULL;
    return new_student;
}

void addHeap(student* newstudent){
    myHeap.count++;
    myHeap.StudentPtr[myHeap.count] = newstudent;
    int current = myHeap.count;
    while(myHeap.StudentPtr[current/2]->rollnumber > newstudent->rollnumber){
        myHeap.StudentPtr[current] = myHeap.StudentPtr[current/2];
        current /= 2;
    }
    myHeap.StudentPtr[current] = newstudent;
}

void add()
{   /// Adding into the list
    student *newstudent = create();
    student* temp;
    temp=list;
    if(temp==NULL)
    {
        list=newstudent;
    }
    else
    {
    while(temp->next!=NULL)
        {
            temp=temp->next;
        }
    temp->next=newstudent;
    }
    print1();
    /// Adding to Heap
    printf("!!!");
    addHeap(newstudent);
}


void PrintHeap(){
    for(int i = 1; i <= myHeap.count; i++){
        printstudent(myHeap.StudentPtr[i]);
    }
}
void deletemin() {
    student* lastElement;
    int child, current;
    lastElement = myHeap.StudentPtr[myHeap.count--];
    for (current = 1; current * 2 <= myHeap.count; current = child) {
        child = current * 2;
        if (child != myHeap.count && myHeap.StudentPtr[child + 1]->rollnumber < myHeap.StudentPtr[child]->rollnumber) {
            child++;
        }

        if (lastElement->rollnumber > myHeap.StudentPtr[child]->rollnumber) {
            myHeap.StudentPtr[current] = myHeap.StudentPtr[child];
        } else 
        {
            break;
        }
    }
    myHeap.StudentPtr[current] = lastElement;
}

 void update()
{
    student *temp;
    temp=list;
    int n;
    printf("\n enter the roll number to be changed");
    scanf("%d",&n);
    while(temp->next!=NULL)
    {
        if(temp->rollnumber == n)
        {
            printf("enter the name and cgpa \n");
            scanf("%s %d",temp->name,&(temp->cgpa));
            print1();
            return;
        }
        temp=temp->next;

    }
    printf("roll number not found");
    print1();
}



void delete()
{
    student *temp;
    temp=list;
    int n;
    printf("\n enter the roll number to be deleted \n");
    scanf("%d",&n);
    while(temp->next!=NULL)
    {
        if(temp->next->rollnumber == n)
        {
            temp->next=temp->next->next;
            print1();
            return;

        }
        temp=temp->next;

    }
    printf("roll number not found");
    print1();
}



int main()
{
    printf("%d", myHeap.count);
    myHeap.StudentPtr[0] = (void*)malloc(sizeof(student));
    myHeap.StudentPtr[0]->rollnumber = -32767;
    int m;
    do{
        printf("\n enter 1 to add and 2 to update 3 to delete 4 0 to exit  \n");
        scanf("%d",&m);
        switch(m)
        {
        case 1:
            {
                add();
                break;
            }
        case 2:
            {
                update();
                break;
            }
        case 3:
            {
                deletemin();
                delete();
                break;
            }
        case 4:
            {
                PrintHeap();
                break;
            }
        }

    }while(m!=0);

}




