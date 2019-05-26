#include <stdio.h>
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

int main(){
    printf("The first 100 Fibonacci numbers are:\n");
    int myArray[101][22];
    fill_fibonacci(myArray);
    for(int i = 0; i <= 100; i++){
        big_print(*(myArray + i));
        printf(" ");
    }
}