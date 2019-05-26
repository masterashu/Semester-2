// Linked List Based Implementation

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct contour{
    double start,end;
    struct contour* next;
} Contour;

Contour *Start = NULL;

void Initialize(double SP, double EP){
    if(Start == NULL){
        Start = (Contour*)malloc(sizeof(Start));
        Start->start = SP;
        Start->end = EP;
        Start->next = NULL;
    }
}

// recursive
void Operation(Contour* aContour){
    if(aContour != NULL){
        Contour *NewContour = (Contour*)malloc(sizeof(Contour));
        NewContour->end = aContour->end;
        aContour->end = (aContour->start + (NewContour->end - aContour->start)/3);
        NewContour->start = (aContour->start + 2*(NewContour->end - aContour->start)/3);
        NewContour->next = aContour->next;
        aContour->next = NewContour;
        Operation(NewContour->next);

    }
    else{
        return;
    }
}

void Print(){
    Contour *aContour = Start;
    while(aContour != NULL){
        printf("[%lf, %lf] ", aContour->start, aContour->end);
        aContour = aContour->next;
    }
    printf("\n");
}

int main(int argc, char* argv[]){    
    int n, SP = 0, EP= 1;
    if(argc < 2){
        scanf("%d", &n);
    }
    else{

    	SP = atoi(argv[1]);
    	EP = atoi(argv[2]);
    	n = atoi(argv[3]);
    }

    Initialize(SP, EP);
    for(int i = 1; i <= n; i++){
        Operation(Start);
        Print();    
    }
    return 0;
}
