#include<stdio.h>

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
int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6};
    printf("%d", array_sum_5(arr, 6));
    return 0;
}
