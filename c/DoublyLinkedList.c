#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

void printList()
{
    struct Node *ptr = head;
    printf("\n[ ");
    while(ptr != NULL){
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    printf(" ]\n");
}

void pushFront(int data){
    struct Node *link = (struct Node *)malloc(sizeof(struct Node));

    link->prev = NULL;
    link->data = data;
    link->next = head;

    head = link;
}

int topFront(){
    return head->data;
}

void popFront(){
    struct Node *tempLink = head->next;
    tempLink->prev = NULL;
    head = head->next;
}

void pushBack(int data)
{
    struct Node *link = (struct Node *)malloc(sizeof(struct Node));
    link->data = data;
    link->next = NULL;

    if(head == NULL)
    {
        head = link;
        link->prev = NULL;
        return;
    }

    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    link->prev = current;
    current->next = link;
    return;
}

int topBack(){
    struct Node *current = head;

    while(current->next != NULL){
        current = current->next;
    }
    return current->data;
}

void popBack()
{
    struct Node *current = head;

    while(current->next->next != NULL){
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

    for(current = head; current != NULL; current = current->next){
        length++;
    }
    return length;
}

void erase(int data){
    struct Node *current = head;

    while(current != NULL && current->data != data){
        current = current->next;
    }

    if(!current){
        return;
    }
    if(current->prev == NULL){
        head = current->next;
    }else if(current->next == NULL){
        current->prev->next = current->next;
    }else{
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    return;
}

bool find(int data)
{
    struct Node *current = head;
    while(current != NULL && current->data != data){
        current = current->next;
    }

    if(current){
        return true;
    }
    return false;

}

void addBefore(int key, int data){
    struct Node *current = head;
    struct Node *link = (struct Node *)malloc(sizeof(struct Node));
    link->data = data;

    if(key == current->data){
        pushFront(data);
        return;
    }
    while(current){
        if(current->next == NULL){
            return;
        }
        if(current->next->data == key){
            link->prev = current->next->prev;
            link->next = current->next;
            current->next = link;
            break;
        }else{
            current = current->next;
        }
    }
    return;
}

void main()
{
    pushFront(10);
    pushFront(20);
    pushFront(30);
    pushFront(40);
    printList();
    addBefore(40, 44);
    addBefore(30, 33);
    printList();
}

