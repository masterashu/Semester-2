#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Trie.h"

int main(){
    Trie* myTrie = CreateNewNode(0); // Sentinal Node
    int choice;
    char word[20];
	do{
		printf("\nEnter choice:\n1. Add a Word\n2. Search a Word\n3. Delete a Word\n4. Print All Words\n5. Autocomplete\n6. Suggest\n0. Exit\n\t:  ");
		scanf("%d", &choice);
		system("clear");
        int data;
		switch(choice){
			case 1:
                printf("Enter a word: ");
                scanf("%s", word);
                myTrie = InsertWord(myTrie, word);
				break;
			case 2:
			    printf("Enter a word: ");
                scanf("%s", word);
				if(SearchWord(myTrie, word)){
					printf("Word Exists!\n");
				}
				else{
					printf("Word doesn't Exist!\n");
				}
                break;
			case 3:
				printf("Enter a word: ");
                scanf("%s", word);
				myTrie = DeleteWord(myTrie, word);
				break;
			case 4:
				PrintAll(myTrie, word, 0);
				break;
			case 5:
				printf("Enter a word: ");
                scanf("%s", word);
				AutoComplete(myTrie, word);
			case 6:
				printf("Enter a word: ");
                scanf("%s", word);
				char buffer[20];
				Suggestion(myTrie, buffer, word, 0, 0);
		}
	}while(choice != 0);
    return 0;
}