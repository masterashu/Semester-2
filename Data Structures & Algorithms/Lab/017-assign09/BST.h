#ifndef BST_H
#define BST_H
struct student{
    char Name[40];
    int RollNo;
    float CGPA;
    struct student *next;
};
typedef struct student Student;

struct studentBst{
    Student *StudentPtr;
    struct studentBst* left;
    struct studentBst* right;
};
typedef struct studentBst StudentBST;

Student* CreateStudent();

Student* GetStudent(int Roll, Student* List);

Student* AddStudent(Student *List, StudentBST **BST);

Student* DeleteStudentByRollNo(int Roll, Student *List, StudentBST **BST);

Student* UpdateStudentByRollNo(int Roll, Student *List, StudentBST **BST);

void PrintStudentDetails(Student *aStudent);

StudentBST* CreateBST(Student* newStudent);

StudentBST* AddStudentBST(StudentBST *newStudentNode, StudentBST *BST);

StudentBST* DeleteStudentBST(Student *aStudent, StudentBST *BST);

Student* FindStudentByRollNo(int Roll, StudentBST *BST);

void PrintBstInOrder(StudentBST *BST);

void PrintBstPreOrder(StudentBST *BST);

void PrintBstPostOrder(StudentBST *BST);

void PrintAll(Student* List);

void PrettyPrint(StudentBST *BST, int count);

#endif