#include <stdio.h>
#include <stdlib.h>
#include "grades-017.h"


/************************ Function Definitions *********************/


void PrintGrades(float grades[], int howmany)
{
  int i;  /* loop variable */

  for (i = 0; i < howmany; i++) {
    printf(" %.2f", grades[i]);
  }

  printf("\n");  /* end of line */
}


void AdjustGrades(float grades[],
                  float adjustments[],
                  int howmany)
{
  float newGrade;
  int i;  /* loop variable */

  for (i = 0; i < howmany; i++) {
    /* This two-step assignment can be done in one step. */
    newGrade = AdjustedGrade(grades[i], adjustments[i]);
    grades[i] = newGrade;
  }
}


float AdjustedGrade(float grade, float adjustment)
{
  grade += adjustment;
  return grade;
}


float MinGrade(float grades[], int howmany){
    float Minimum = grades[0];
    for(int i = 0; i < howmany; i++){
        if(grades[i] < Minimum){
            Minimum = grades[i];
        }
    }
    return Minimum;
}

float MaxGrade(float grades[], int howmany){
    float Maximum = grades[0];
    for(int i = 0; i < howmany; i++){
        if(grades[i] > Maximum){
            Maximum = grades[i];
        }
    }
    return Maximum;
}

float SumGradesIterative(float grades[], int howmany){
    int start = 0, end = howmany - 1;
    float Sum = 0;
    while(start < end){
        Sum += (grades[start] + grades[end]);
        start++,end--;
    }
    if(start == end){
        Sum += grades[start];
    }
    return Sum;
}

float SumGradesRecursive(float grades[], int howmany){
    static int index = 0;
    if(index == howmany){
        return 0;
    }
    else{
        index++;
        return grades[index-1] + SumGradesRecursive(grades, howmany);
    }
}

float AverageGrade(float grades[], int howmany){
    float Sum = SumGradesIterative(grades, howmany);
    float Average = Sum / howmany;
    return Average;
}