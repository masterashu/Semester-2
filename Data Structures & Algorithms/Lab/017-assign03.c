#include <stdio.h>
#include <stdlib.h>

void recursive_factorial(long int * num, long int * fact){
    if((*num) > 1){
        *fact = (*fact) * (*num);
        *num = *num - 1;
        recursive_factorial(num, fact);
    }
}

void big_print(int* a){
    int i = 21;
    while(*(a+i) == 0 && i > 0){
        i--;
    }
    while(i >= 0){
        printf("%d", *(a+i));
        i--;
    }
}
void big_add(int *a, int*b, int*c){
    int carry = 0;
    for(int i = 0; i < 22; i++){
        c[i] = (a[i] + b[i] + carry) % 10;
        carry =  (a[i] + b[i] + carry) / 10;
    }
}

void big_set(int* a, long long int n){
    for(int i = 0; i < 22; i++){
        a[i] = 0;
    }
    int i = 0;
    while(n > 0){
        a[i++] = n % 10;
        n = n / 10;
    }
}

void fill_fibonacci(int arr[101][22]){
    big_set(*arr, 0);
    big_set(*(arr + 1), 1);
    for(int i = 2; i <= 100; i++){
        big_set(*(arr + i), 0);
    }
    for(int i = 2; i <= 100; i++){
        big_add(*(arr + i - 2), *(arr + i - 1), *(arr + i));
    }
}

void numbers_sum(int * array, int * size, long int * sum){
    *sum = 0;
    for(int i = 0; i < *size; i++){
        *sum = *sum + *(array + i);
    }
}
void swap(int * a, int * b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}


int main(){
    int choice;
	do{
		printf("Enter choice:\n1. Recursive function to compute factorial of a given number\n2. Function to fill an array with the first 100 Fibonacci numbers.\n3. Sum of numbers\n4. Swap two numbers\n0. Exit\n\t:  ");
		scanf("%d", &choice);
		system("cls");
		switch(choice){
			case 1:
                printf("Enter a number: ");
                long int n, m, f = 1;
                scanf("%ld", &n);
                m = n;
				recursive_factorial(&m, &f);
                printf("The factorial of %ld is %ld.\n", n, f);
				break;
			case 2:
                printf("The first 100 Fibonacci numbers are:\n");
                int myArray[101][22];
                fill_fibonacci(myArray);
                for(int i = 0; i <= 20; i++){
                    big_print(*(myArray + i));
                    printf(" ");
                }
                break;
			case 3:
                printf("Enter how many numbers to add: ");
                int num;
                long int sum;
                scanf("%d", &num);
                int* arr = (void*)malloc(sizeof(int)*num);
                for(int i = 0; i < num; i++){
                    scanf("%d", arr+i);
                }
                numbers_sum(arr, &num, &sum);
                printf("The sum is %ld.\n", sum);
				break;
			case 4:
                printf("Enter two number: ");
                int num1, num2;
                scanf("%d %d", &num1, &num2);
				swap(&num1, &num2);
                printf("num1 = %d, num2 = %d\n", num1, num2);

				break;
		}
	}while(choice != 0);
    return 0;
}