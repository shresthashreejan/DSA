#include "data_structures/linked_list.h"

Node* CreateNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->data = data;
    node->next = NULL;
    return node;
}

void InsertNode(Node** head, int data, const char* position)
{
    if (strcmp(position, INSERT_END) == 0)
    {
        Node* newNode = CreateNode(data);
        if (*head == NULL)
        {
            *head = newNode;
            return;
        }

        Node* temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
    else if (strcmp(position, INSERT_BEGIN) == 0)
    {
        Node* newNode = CreateNode(data);
        newNode->next = *head;
        *head = newNode;
    }
    else printf("Invalid position\n");
}

void DisplayNodes(Node* head)
{
    Node* temp = head;
    printf("LINKED LIST\n");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void DeallocateMemory(Node* head)
{
    Node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void LinkedList(void)
{
    Node* head = NULL;
    InsertNode(&head, 20, INSERT_END);
    InsertNode(&head, 30, INSERT_END);
    InsertNode(&head, 10, INSERT_BEGIN);
    DisplayNodes(head);
    DeallocateMemory(head);
    printf("\n");
}