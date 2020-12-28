#include<iostream>
using namespace std;

template<class T>

class Node{

private:
    T data;
    Node *next;

public:
    Node(){
        next = NULL;
    }
    Node(T data){
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
    T getData(){
        return data;
    }
    void setdata(T data){
        this->data = data;
    }

};

template<class T>
class Stack{
    Node<T> *head;
public:
    Stack(){
        head = NULL;
    }
    void push(T data){
        Node<T> *node = new Node<T>(data);
        node->setNext(head);
        head = node;
    }

    T pop(){
        if(head == NULL){
            cout<<"Stack is Empty"<<endl;
            return NULL;
        }
        else{
            T data = head->getData();
            head = head->getNext();
            return data;
        }
    }

     T peek(){
        if(head == NULL){
            cout<<"Stack is Empty"<<endl;
            return NULL;
        }
        else{
            T data = head->getData();
            return data;
        }
    }
};

int main(){
    Stack<string> s;
    s.push("Adinath");
    s.push("Hrishi Gunda");
    s.push("Rupali");
    s.push("Gadi wala aya ghar se khachara nikal");
    s.push("Deepika");

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.peek()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.peek()<<endl;



}
