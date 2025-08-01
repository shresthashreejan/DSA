#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INSERT_BEGIN "begin"
#define INSERT_END "end"

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* CreateNode(int data);
void InsertNode(Node** head, int data, const char* position);
void DisplayNodes(Node* head);
void DeallocateMemory(Node* head);
void LinkedList(void);

#endif