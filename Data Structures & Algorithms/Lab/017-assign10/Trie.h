#ifndef TRIE_H
#define TRIE_H

#define CHAR_INSENSITIVE

#ifdef CHAR_SENSITIVE
#define CHARACTER_NO 52
#endif
#ifdef CHAR_INSENSITIVE
#define CHARACTER_NO 26
#endif

struct trie{
    char data;
    struct trie* next[CHARACTER_NO];
    int isEnd;
    int childs;
};
typedef struct trie Trie;

int GetIndex(char ch);

Trie* CreateNewNode(char ch);

Trie* InsertWord(Trie* myTrie, char* word);

Trie* DeleteWord(Trie* myTrie, char* word);

int SearchWord(Trie* myTrie, char* word);

void PrintAll(Trie* myTrie, char *word, int length);

void AutoComplete(Trie* Root, char *word);

void Suggestion(Trie* myTrie, char *buffer, char* word, int length, int misspelled);

#endif