#include <stdio.h>
#include <stdlib.h>
#include "grades-017.h"

#define MAX_GRADES 20 /* The max. number of grades per student. */

int main()
{
	float adjustments[MAX_GRADES]; /* Grade adjustments for all students. */
	float grades[MAX_GRADES];	  /* Grades for current student.         */
	int numGrades;				   /* Number of adjustments.              */
	int numStudents;			   /* Number of students.                 */
	int studentNum;				   /* Index of current student.           */
	int i;						   /* Looping variable.                   */

	printf("How many grades per student? ");
	scanf("%d", &numGrades);
	if (numGrades < 1 || numGrades > MAX_GRADES)
	{
		printf("I can only handle 1..%d grades!", MAX_GRADES);
		exit(1); /* Terminate program, return error status. */
	}

	for (i = 0; i < numGrades; i++)
	{
		printf("\nEnter adjustment for HW%d> ", i + 1);
		scanf("%f", &adjustments[i]);
	}

	printf("\nHow many students? ");
	scanf("%d", &numStudents);

	for (studentNum = 1; studentNum <= numStudents; studentNum++)
	{
		printf("\n"); /* Blank line */

		/* Get each grade for the current student. */

		printf("Student #%d\n", studentNum);

		for (i = 0; i < numGrades; i++)
		{
			printf("\nEnter grade for HW%d> ", i + 1);
			scanf("%f", &grades[i]);
		}

		/* Print grades before and after adjustment. */

		printf("\n\nOld Student #%d grades:", studentNum);
		PrintGrades(grades, numGrades);
		int choice;
		do{
			printf("Main Menu\n1.Adjust Grades\n2.Find Minimum Grades\n3.Find Maximum\n4.Find Sum of Grades\n5.Find Average Grade\n\t Enter your choice: ");
			scanf("%d", &choice);
			switch (choice)
			{
				case 1:
					AdjustGrades(grades, adjustments, numGrades);
					printf("\nNew Student #%d grades:", studentNum);
					PrintGrades(grades, numGrades);
					break;
				case 2:
					printf("The Minimum Grade is %f.\n", MinGrade(grades, numGrades));
					break;
				case 3:
					printf("The Maximum Grade is %f.\n", MaxGrade(grades, numGrades));
					break;
				case 4:
					printf("The Sum of Grades is %f.\n", SumGradesIterative(grades, numGrades));
					break;
				case 5:
					printf("The Average Grade is %f.\n", AverageGrade(grades, numGrades));
					break;
			}
			
		}while(choice != 0);
	}
	return 0;
}