#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a doubly linked list node
typedef struct Node {
    char url[21];
    struct Node* prev;
    struct Node* next;
} Node;

// Structure to represent the Browser History
typedef struct {
    Node* current;
} BrowserHistory;

// Function to create a new node with the given URL
Node* createNode(const char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Initialize the BrowserHistory with the homepage
BrowserHistory* browserHistoryCreate(const char* homepage) {
    BrowserHistory* obj = (BrowserHistory*)malloc(sizeof(BrowserHistory));
    obj->current = createNode(homepage);
    return obj;
}

// Visit a new URL and clear forward history
void browserHistoryVisit(BrowserHistory* obj,const char* url) {
    Node* newNode = createNode(url);
    obj->current->next = newNode;
    newNode->prev = obj->current;
    obj->current = newNode;
}

// Move back in history by the specified number of steps
char* browserHistoryBack(BrowserHistory* obj, int steps) {
    while (steps-- > 0 && obj->current->prev != NULL) {
        obj->current = obj->current->prev;
    }
    return obj->current->url;
}

// Move forward in history by the specified number of steps
char* browserHistoryForward(BrowserHistory* obj, int steps) {
    while (steps-- > 0 && obj->current->next != NULL) {
        obj->current = obj->current->next;
    }
    return obj->current->url;
}

// Free the allocated memory for the BrowserHistory
void browserHistoryFree(BrowserHistory* obj) {
    Node* temp;
    while (obj->current->prev != NULL) {
        obj->current = obj->current->prev;
    }
    while (obj->current != NULL) {
        temp = obj->current;
        obj->current = obj->current->next;
        free(temp);
    }
    free(obj);
}

int main() {
    BrowserHistory* browserHistory = browserHistoryCreate("leetcode.com");
    browserHistoryVisit(browserHistory, "google.com");       // Visit "google.com"
    browserHistoryVisit(browserHistory, "facebook.com");     // Visit "facebook.com"
    browserHistoryVisit(browserHistory, "youtube.com");      // Visit "youtube.com"
    printf("%s\n", browserHistoryBack(browserHistory, 1));   // Move back to "facebook.com"
    printf("%s\n", browserHistoryBack(browserHistory, 1));   // Move back to "google.com"
    printf("%s\n", browserHistoryForward(browserHistory, 1)); // Move forward to "facebook.com"
    browserHistoryVisit(browserHistory, "linkedin.com");     // Visit "linkedin.com"
    printf("%s\n", browserHistoryForward(browserHistory, 2)); // Attempt to move forward
    printf("%s\n", browserHistoryBack(browserHistory, 2));   // Move back to "google.com"
    printf("%s\n", browserHistoryBack(browserHistory, 7));   // Move back to "leetcode.com"
    
    browserHistoryFree(browserHistory);
    return 0;
}

