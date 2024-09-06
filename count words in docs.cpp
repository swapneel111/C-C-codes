#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100003

struct Node {
    char* word;
    int count;
    struct Node* next;
};

struct Node* hashTable[TABLE_SIZE];

// Hash function
int hash(const char* str) {
    int hash[TABLE_SIZE];
	
	for(int i=0;i<=TABLE_SIZE;i++) {
		hash[str[i]]++;
	}
}

// Insert or update the word count
void insertOrUpdate(const char* word) {
    unsigned int index = hash(word);
    struct Node* current = hashTable[index];
    
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->word = strdup(word);
    newNode->count = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Print word frequencies
void printFrequencies() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* current = hashTable[i];
        while (current != NULL) {
            printf("%s: %d\n", current->word, current->count);
            current = current->next;
        }
    }
}

// Free allocated memory
void freeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* current = hashTable[i];
        while (current != NULL) {
            struct Node* toDelete = current;
            current = current->next;
            free(toDelete->word);
            free(toDelete);
        }
        hashTable[i] = NULL;
    }
}

int main() {
    char line[1000];
    printf("Enter the document (end with Ctrl+D or EOF):\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    while (fgets(line, sizeof(line), stdin)) {
        char* token = strtok(line, " \t\n,.!?;:");
        while (token != NULL) {
            insertOrUpdate(token);
            token = strtok(NULL, " \t\n,.!?;:");
        }
    }

    printFrequencies();
    freeHashTable();

    return 0;
}

