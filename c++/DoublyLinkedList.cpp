#include<iostream>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;
};

class DoublyLinkedList{
public:
    int length;
    Node* head;

    DoublyLinkedList();
    ~DoublyLinkedList();

    void pushFront(int data);
    int topFront();
    void popFront();
    void pushBack(int data);
    int topBack();
    void popBack();
    void find(int key);
    void erase(int key);
    bool isEmpty();
    void addBefore(int key, int data);
    void addAfter(int key, int data);
    void print();
};

DoublyLinkedList::DoublyLinkedList(){
    this->length = 0;
    this->head = NULL;
}

DoublyLinkedList::~DoublyLinkedList(){
    cout << "List Deleted" << endl;
}

void DoublyLinkedList::pushFront(int data){
    Node* node = new Node();
    node->data = data;
    node->prev = NULL;

    if(this->head){
        node->next = this->head;
        this->head->prev = node;
    }else{
        node->next = NULL;
    }
    
    this->head = node;
    this->length++;
}

int DoublyLinkedList::topFront(){
    return this->head->data;
}

void DoublyLinkedList::popFront(){
    this->head->next->prev = NULL;
    this->head = this->head->next;
}

void DoublyLinkedList::pushBack(int data){
    Node *current = this->head;
    while(current->next){
        current = current->next;
    }
    Node* node = new Node();
    node->data = data;
    node->prev = current;
    current->next = node;
}

int DoublyLinkedList::topBack(){
    Node *current = this->head;

    if(!current){
        return -1;
    }
    while(current->next){
        current = current->next;
    }
    return current->data;
}

void DoublyLinkedList::popBack(){
    Node *current = this->head;
    while (current->next->next)
    {
        current = current->next;
    }
    current->next = NULL;
}

void DoublyLinkedList::find(int key){
    Node *current = this->head;
    while(current != NULL && current->data != key){
        current = current->next;
    }
    if(current){
        printf("Found Node: %d\n", current->data);
    }else{
        printf("Not Found\n");
    }
}

void DoublyLinkedList::erase(int key){
    Node *current = this->head;
    while(current != NULL && current->data != key){
        current = current->next;
    }
    if(current == head){
        current->next->prev = NULL;
        this->head = current->next;
        return;
    }
    if(current->next == NULL){
        current->prev->next = current->next;
        return;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;    
    return;
}

bool DoublyLinkedList::isEmpty(){
    return this->head == NULL;
}

void DoublyLinkedList::addBefore(int key, int data){
    Node *current = this->head;
    while(current != NULL && current->data != key){
        current = current->next;
    }
    Node *node = new Node();
    node->data = data;

    if(current == head){
        this->head = node;
    }else{
        current->prev->next = node;
    }
    node->prev = current->prev;
    node->next = current;
    current->prev = node;
}

void DoublyLinkedList::addAfter(int key, int data){
    Node *current = this->head;
    while(current != NULL && current->data != key){
        current = current->next;
    }
    Node *node = new Node();
    node->data = data;
    node->prev = current;
    node->next = current->next;

    if(current->next != NULL){
        current->next->prev = node;
    }
    current->next = node;
}

void DoublyLinkedList::print(){
    Node* head = this->head;
    while(head){
        cout << head->data << " => ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    DoublyLinkedList* dlist = new DoublyLinkedList();
    for(int i = 0; i < 5; ++i){
        dlist->pushFront(i);
    }
    dlist->print();
    printf("Length : %d\n", dlist->length);
    printf("TopFront : %d\n", dlist->topFront());
    printf("TopBack : %d\n", dlist->topBack());
    printf("Is Empty: %d\n", dlist->isEmpty());
    // dlist->popFront();
    // dlist->popBack();
    dlist->pushBack(10);
    dlist->pushBack(20);

    dlist->find(22);
    dlist->erase(20);

    dlist->addBefore(4, 44);

    dlist->print();
    delete dlist;
    return 0;
}