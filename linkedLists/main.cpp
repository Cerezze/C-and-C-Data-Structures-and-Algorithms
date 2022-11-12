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
        int length;
    
    public:
        LinkedList();
        ~LinkedList();
        void push(int);
        void pop();
        void unshift(int);
        void shift();
        Node *get(int);
        void set(int, int);
        void insert(int, int);
        void destroy(int);
        void displayLL();
};

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    length = 0;
}

LinkedList::~LinkedList(){
    while(head != NULL){
        pop();
    }
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
    
    length++;
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
    
    length--;
}

void LinkedList::unshift(int val){
    Node *newNode = new Node;
    newNode->data = val;
    
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
    
    length++;
}

void LinkedList::shift(){
    if(head == NULL){
        std::cout<<"List Empty, ";
    }else if(head == tail){
        head = NULL;
        tail = NULL;
    }else{
        Node *oldHead = head;
        
        head = oldHead->next;
            
        delete oldHead;
    }
    
    length--;
}

Node *LinkedList::get(int index){
    Node *current = head;
    int count = 0;
    if(index > 0){
        while(count < index - 1){
            current = current->next;
            count++;
        }
        return current;
    }else{
        std::cout<<"index must be larger than 0"<<std::endl;
        return NULL;
    }
}

void LinkedList::set(int index, int val){
    get(index)->data = val;
    
    std::cout<<"index "<<index<<" set to "<<val<<std::endl;
}

void LinkedList::insert(int index, int val){
    if(index == 1){
        unshift(val);
    }else if(index == length){
        push(val);
    }else{
        Node *newNode = new Node;
        newNode->data = val;
        Node *BN = get(index - 1);
        Node *N = BN->next;
        
        BN->next = newNode;
        newNode->next = N;
    }
    
    length++;
}

void LinkedList::destroy(int index){
    if(index == 1){
        shift();
    }else if(index == length){
        pop();
    }else{
        Node *BN = get(index - 1);
        Node *N = BN->next;
        
        BN->next = N->next;
        
        delete N;
    }
    
    length--;
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
    LL.push(2);
    
    LL.pop();
    LL.pop();
    
    LL.unshift(7);
    LL.unshift(3);
    LL.unshift(5);
    
    LL.shift();
    LL.shift();
    
    LL.set(1, 2);
    LL.set(3, 17);
    
    LL.insert(2, 2);
    LL.insert(2, 1);
    LL.insert(3, 1);
    
    LL.destroy(2);
    LL.destroy(2);
    LL.destroy(3);
    LL.destroy(4);
    LL.destroy(1);
    
    LL.displayLL();

    return 0;
}
