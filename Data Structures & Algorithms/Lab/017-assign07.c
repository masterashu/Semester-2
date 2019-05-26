// Ashutosh Chauhan
// Roll No- S20180010017

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 50

struct timespec StartTime, EndTime;

// Sum of array using array
int array_sum_1(int arr[], int Length){
    int sum = 0;
    for(int i = 0; i < Length ; i++){
        sum += arr[i];
    }
    return sum;
}

// Recursive sum of an array
int array_sum_2(int arr[], int Length){
    static int index = 0;
    if(index >= Length){
        index = 0;
        return 0;
    }
    else{
        index++;
        return arr[index - 1] + array_sum_2(arr, Length);
    }
}

// Gaussian Technique to find Sum of an Array (contigous only)
int array_sum_3(int arr[], int Length){
    int Sum = arr[0] + arr[Length - 1];
    if(Length % 2 == 0){
        Sum = Sum*(Length/2);
    }
    else{
        Sum = Sum*(Length-1)/2 + Sum/2;
    }
    return Sum;
}

// Sum of N Natural Number series formula 
int array_sum_4(int arr[], int Length){
    return (Length*(Length+1))/2;
}

// Using Multiple Pointers from ending and begining
int array_sum_5(int arr[], int Length){
    int Sum = 0;
    int begin = 0, end = Length - 1;
    while(begin < end){
        Sum += arr[begin] + arr[end];
        begin++;
        end--;
    }
    // Case for odd elements
    if(begin == end){
        Sum += arr[begin];
    }
    return Sum;
}

int populate_random(int arr[], int Length, int min, int max){
    for(int i = 0; i < Length; i++){
        arr[i] = min + (rand())%(max-min+1);
    }
}

// r for random
// d for custom
int main(int argc, char const *argv[])
{
    int Length, arr[MAX_SIZE], min, max;
    int start, end;
    char type;
    if(argc > 1){
        if(strcmp(argv[1], "r") == 0){
            type = 'r';
            Length = atoi(argv[2]);
            min = atoi(argv[3]);
            max = atoi(argv[4]);
            populate_random(arr, Length, min, max);
        }
        else{
            type = 'd';
            Length = atoi(argv[2]);
            if(Length + 2 >= argc){
                printf("Not enough Command Line arguments!\n");
                exit(1);
            }
            for (int i = 0; i < Length; i++){
                arr[i] = atoi(argv[i+3]);
            }
        }
    }
    else{
        printf("Enter type of sequence: \n1. Random\n2. Continous\n3. Custom\n:");
        int choice;
        scanf("%d", &choice);
        switch(choice){
                case 1: 
                printf("Enter total numbers, minimun and Maximum Range\n");
                scanf("%d %d %d", &Length, &min, &max);
                populate_random(arr, Length, min, max);
                type = 'r';
                break;
            case 2:
                printf("Enter Starting Number: ");
                scanf("%d", &start);
                printf("Enter Ending Number: ");
                scanf("%d", &end);
                for(int i = 0; i <= end - start; i++){
                    arr[i] = i + start;
                }
                Length = end - start + 1;
                type = 'c';
                break;
            case 3:
                printf("Enter no. of Inputs\n");
                scanf("%d", &Length);
                printf("Enter numbers: ");
                for(int i = 0; i < Length; i++){
                    scanf("%d", &arr[i]);
                }
                type = 'd';
                break;
            default:
                break;
        }
    }
    if(argc > 1){
        printf("Your Command Line Input: ");
        for(int i = 0; i < Length; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    int choice;
    long int time_taken;
	do{
		printf("\nEnter choice:\n1. Use Loops\n2.Use Recursive\n3.Gauss Technique\n4.Use Formula\n5.Using Multiple Pointers\n0.Exit\n\t:");
		scanf("%d", &choice);
		switch(choice){
			case 1:
                timespec_get(&StartTime, TIME_UTC);
                printf("Sum of array is %d.\n", array_sum_1(arr, Length));
                timespec_get(&EndTime, TIME_UTC);
                time_taken = EndTime.tv_nsec, StartTime.tv_nsec;
                printf("1st Function took %ld ns of time.\n", time_taken);
				break;
			case 2:
                timespec_get(&StartTime, TIME_UTC);
                printf("Sum of array is %d.\n", array_sum_2(arr, Length));
                timespec_get(&EndTime, TIME_UTC);
                time_taken = EndTime.tv_nsec - StartTime.tv_nsec;
                printf("1st Function took %ld ns of time.\n", time_taken);
                break;
			case 3:
                timespec_get(&StartTime, TIME_UTC);
                printf("Sum of array is %d.\n", array_sum_3(arr, Length));
                timespec_get(&EndTime, TIME_UTC);
                time_taken = EndTime.tv_nsec - StartTime.tv_nsec;
                printf("1st Function took %ld ns of time.\n", time_taken);
				break;
			case 4:
                timespec_get(&StartTime, TIME_UTC);
                printf("Sum of array is %d.\n", array_sum_4(arr, Length));
                timespec_get(&EndTime, TIME_UTC);
                time_taken = EndTime.tv_nsec - StartTime.tv_nsec;
                printf("1st Function took %ld ns of time.\n", time_taken);
				break;
            case 5:
                timespec_get(&StartTime, TIME_UTC);
                printf("Sum of array is %d.\n", array_sum_4(arr, Length));
                timespec_get(&EndTime, TIME_UTC);
                time_taken = EndTime.tv_nsec - StartTime.tv_nsec;
                printf("1st Function took %ld ns of time.\n", time_taken);
                break;
		}
	}while(choice != 0);
    return 0;
}
