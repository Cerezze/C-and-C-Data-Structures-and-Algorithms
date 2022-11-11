#include <iostream>

class Node{
        int data;
        Node *next;
        
        friend class LinkedList;
};

class LinkedList{
    private:
        Node *head;
        Node *tail;
    
    public:
        LinkedList();
        void push(int);
        void pop();
        void displayLL();
};

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
}

void LinkedList::push(int val){
    Node *newNode = new Node;
    newNode->data = val;
    
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::pop(){
    
    if(head == NULL){
        std::cout<<"List Empty, ";
    }else if(head == tail){
        head = NULL;
        tail = NULL;
    }else{
        Node *oldTail = tail;
        Node *current = head;
        Node *newTail = current;
            
        while(current->next){
            newTail = current;
            current = current->next;
        }
        tail = newTail;
        tail->next = NULL;
            
        delete oldTail;
    }
}

void LinkedList::displayLL(){
    Node *current = head;
    
    while(current){
        std::cout<<current->data<<" -> ";
        current = current->next;
    }
    std::cout<<"null";
}

int main()
{
    LinkedList LL;
    
    LL.push(5);
    LL.push(3);
    LL.push(7);
    LL.push(8);
    
    LL.pop();
    LL.pop();
    LL.pop();
    LL.pop();
    LL.pop();
    
    LL.displayLL();

    return 0;
}
