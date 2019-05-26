/************************ Function Prototypes *********************/


/*
 * Function: PrintGrades
 * Usage: PrintGrades(grades, howmany)
 * ---------------------------
 * Prints the integer grades in the array `grades'.
 * `Howmany' indicates the number of grades.
 * Grades are all printed on one line separated by
 * spaces and terminated by a newline.
 */
void PrintGrades(float grades[], int howmany);

/*
 * Function: AdjustGrades
 * Usage: AdjustGrades(grades, adjustments, howmany)
 * -------------------------------
 * Adjusts each grade in the `grades' array using
 * the corresponding change in the `adjustments' array.
 * `Howmany' indicates the number of grades.  On return
 * from the function, the `grades' array that was passed
 * will contain the new grades.
 */
void AdjustGrades(float grades[],
                  float adjustments[],
                  int howmany);

/*
 * Function: AdjustedGrade
 * Usage: newGrade = AdjustedGrade(grade, adjustment)
 * -------------------------------
 * Adjusts one grade and returns the new grade.
 * Currently, the adjustment technique is to
 * add the adjustment to the grade.
 */
float AdjustedGrade(float grade, float adjustment);

/*
 *
 * Function: MinGrade
 * Usage: mingrade = MinGrade(grades, howmany)
 * -------------------------------
 * Finds the Minimum grade in the Grades Array
 *
 */
float MinGrade(float grades[], int howmany);

/*
 *
 * Function: MaxGrade
 * Usage: maxgrade = MaxGrade(grades, howmany)
 * -------------------------------
 * Finds the Maximum grade in the Grades Array
 *
 */
float MaxGrade(float grades[], int howmany);

/*
 *
 * Function: SumGradesIterative
 * Usage: sumGrades = SumGradesIterative(grades, howmany)
 * -------------------------------
 * Finds the Sum of all the grades in the Grades Array
 *
 */
float SumGradesIterative(float grades[], int howmany);

/*
 *
 * Function: SumGradesRecursive
 * Usage: sumGrades = SumGradesRecursive(grades, howmany)
 * -------------------------------
 * Finds the Sum of all the grades in the Grades Array
 *
 */
float SumGradesRecursive(float grades[], int howmany);

/*
 *
 * Function: AverageGrade
 * Usage: avgGrade = AverageGrade(grades, howmany)
 * -------------------------------
 * Finds the Minimum grade in the Grades Array
 *
 */
float AverageGrade(float grades[], int howmany);