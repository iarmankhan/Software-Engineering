#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

void printList()
{
    struct Node *ptr = head;
    printf("\n[ ");

    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }

    printf(" ]\n");
}

void insertAtFirst(int data)
{
    struct Node *link = (struct Node *)malloc(sizeof(struct Node));

    link->data = data;
    link->next = head;

    head = link;
}

int topFront()
{
    return head->data;
}

struct Node *deleteFirst()
{
    struct Node *tempLink = head;
    head = head->next;
    return tempLink;
}

void pushBack(int data)
{
    struct Node *link = (struct Node *)malloc(sizeof(struct Node));
    link->data = data;
    link->next = NULL;

    if (head == NULL)
    {
        head = link;
        return;
    }
    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = link;
    return;
}

int topBack()
{
    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    return current->data;
}

void popBack()
{
    struct Node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    current->next = NULL;
    return;
}

bool isEmpty()
{
    return head == NULL;
}

int length()
{
    int length = 0;
    struct Node *current;

    for (current = head; current != NULL; current = current->next)
    {
        length++;
    }
    return length;
}

void erase(int data){
    struct Node *current = head;

    if (head == NULL)
    {
        return;
    }

    if(current->data == data){
        head = current->next;
        return;
    }

    while (current->next->data != data)
    {
        if (current->next == NULL)
        {
            return;
        }
        else
        {
            current = current->next;
        }
    }
    current->next = current->next->next;
    return;
}

struct Node *find(int data)
{
    struct Node *current = head;

    if (head == NULL)
    {
        return NULL;
    }

    while (current->data != data)
    {
        if (current->next == NULL)
        {
            return NULL;
        }
        else
        {
            current = current->next;
        }
    }
    return current;
}

void addBefore(int key, int data){
    if (head == NULL)
    {
        return;
    }
    struct Node *current = head;

    struct Node *link = (struct Node *)malloc(sizeof(struct Node));
    link->data = data;
    
    if(current->data == key){
        link->next = current;
        head = link;
        return;
    }

    while (current->next->data != key)
    {
        if (current->next == NULL)
        {
            return;
        }
        else
        {
            current = current->next;
        }
    }
    
    link->next = current->next;
    current->next = link;
    return;
    
}

int main()
{
    insertAtFirst(10);
    insertAtFirst(20);
    insertAtFirst(30);
    printList();
    pushBack(22);
    pushBack(32);
    pushBack(52);
    printList();
    popBack();
    popBack();
    printList();
    printf("%d\n", topBack());
    printf("%d\n", topFront());
    erase(10);
    printList();
    addBefore(20, 22);
    addBefore(30, 33);
    addBefore(33, 44);
    printList();
}