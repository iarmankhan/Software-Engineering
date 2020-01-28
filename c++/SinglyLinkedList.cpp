#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class SinglyLinkedList{
public:
    int length;
    Node* head;

    SinglyLinkedList();
    ~SinglyLinkedList();
    
    void pushFront(int data);
    void topFront();
    void popFront();
    void pushBack(int data);
    void topBack();
    void popBack();
    void find(int data);
    void erase(int data);
    bool isEmpty();
    void addBefore(int key, int data);
    void print();
};

SinglyLinkedList::SinglyLinkedList(){
    this->length = 0;
    this->head = NULL;
}

SinglyLinkedList::~SinglyLinkedList(){
    cout << "LIST DELETED" << endl;
}

void SinglyLinkedList::pushFront(int data){
    Node* node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
    this->length++;
}

void SinglyLinkedList::topFront(){
    cout << "Top Front : " << this->head->data << endl;
}

void SinglyLinkedList::popFront(){
    this->head = this->head->next;
}

void SinglyLinkedList::pushBack(int data){
    Node* head = this->head;
    while (head->next)
    {
        head = head->next;
    }
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    head->next = node;
}

void SinglyLinkedList::topBack(){
    Node* head = this->head;
    while(head->next){
        head = head->next;
    }
    cout << head->data << endl;
}

void SinglyLinkedList::popBack(){
    Node* head = this->head;
    while(head->next->next){
        head = head->next;
    }
    head->next = NULL;
}

void SinglyLinkedList::find(int data){

    Node* head = this->head;
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }

    while (head->data != data)
    {
        if (head->next == NULL)
        {
            cout << "Not found" << endl;
            return;
        }
        else
        {
            head = head->next;
        }
    }
    cout << "Found : " << head->data << endl; 
}

void SinglyLinkedList::erase(int data){
    Node* head = this->head;

    if (head == NULL)
    {
        return;
    }

    if(head->data == data){
        head = head->next;
        return;
    }

    while (head->next->data != data)
    {
        if (head->next == NULL)
        {
            return;
        }
        else
        {
            head = head->next;
        }
    }
    head->next = head->next->next;
    return;
}

void SinglyLinkedList::addBefore(int key, int data){
    Node* head = this->head;

    if (head == NULL)
    {
        return;
    }

    Node* node = new Node();
    node->data = data;
    
    if(head->data == key){
        node->next = head;
        this->head = node;
        return;
    }

    while (head->next->data != key)
    {
        if (head->next == NULL)
        {
            return;
        }
        else
        {
            head = head->next;
        }
    }
   
    node->next = head->next;
    head->next = node;
    return;
}

void SinglyLinkedList::print(){
    Node* head = this->head;
    while(head){
        cout << head->data << " => ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main(){
    SinglyLinkedList* list = new SinglyLinkedList();
    for(int i = 0; i < 5; ++i){
        list->pushFront(i);
    }
    list->print();
    list->addBefore(3, 10);
    list->print();

    std::cout << "List Length: " << list->length << std::endl;
    delete list;
    return 0;
}