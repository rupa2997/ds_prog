#include<iostream>
using namespace std;

class Node{

private:
    int data;
    Node *next;

public:
    Node(){
        next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        next = NULL;
    }
    Node *getNext(){
        return next;
    }
    void setNext(Node *next){
        this->next = next;
    }
    int getData(){
        return data;
    }
    void setdata(int data){
        this->data = data;
    }

};

class Stack{
    Node *head;
public:
    Stack(){
        head = NULL;
    }
    void push(int data){
        Node *node = new Node(data);
        node->setNext(head);
        head = node;
    }

    int pop(){
        if(head == NULL){
            cout<<"Stack is Empty"<<endl;
            return -9999;
        }
        else{
            int data = head->getData();
            head = head->getNext();
            return data;
        }
    }

     int peek(){
        if(head == NULL){
            cout<<"Stack is Empty"<<endl;
            return -9999;
        }
        else{
            int data = head->getData();
            return data;
        }
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.peek()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.peek()<<endl;



}
