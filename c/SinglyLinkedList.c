#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node* next;
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

void insertAtFirst(int data){
    struct Node *link = (struct Node*) malloc(sizeof(struct Node));

    link->data = data;
    link->next = head;

    head = link;
}

struct Node* deleteFirst()
{
    struct Node *tempLink = head;
    head = head->next;
    return tempLink;
}

bool isEmpty()
{
    return head == NULL;
}  

int length(){
    int length = 0;
    struct Node *current;

    for(current = head; current != NULL; current = current->next){
        length++;
    }
    return length;
}

struct Node* find(int data){
    struct Node* current = head;

    if(head == NULL){
        return NULL;
    }

    while(current->data != data){
        if(current->next == NULL){
            return NULL;
        }else{
            current = current->next;
        }
    }
    return current;
}

struct Node* delete(int data){
    struct Node* current = head;
    struct Node* previous = NULL;

    if(head == NULL){
        return NULL;
    }
    while(current->data != data){
        if(current->next == NULL){
            return NULL;
        }else{
            previous = current;
            current = current->next;
        }
    }
}

int main(){
    insertAtFirst(10);
    insertAtFirst(20);
    insertAtFirst(30);
    printList();
}