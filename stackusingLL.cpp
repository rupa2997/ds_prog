#include<iostream>
using namespace std;
class Node{
    private:
        int data;
        Node *next;
    public:
        Node(){

            next=NULL;
        }
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
         ~Node(){
        next = NULL;
    }
        Node *getNext(){
            return next;
        }
        void setNext(Node *next){
            this->next=next;
        }
        int getData(){
            return data;
        }
        void setData(int data){
            this->data=data;
        }

};

class Stack{
private:
    Node* head;
public:
    Stack(){
        head=NULL;
    }
    void push(int data){
        Node* node=new Node(data);
        if(head==NULL){
            head=node;
        }else{
            node->setNext(head);
            head=node;
        }

    }
    int pop(){
        if(head==NULL){
            cout<<"Empty stack: ";
            return -1;
        }else{
            Node* temp=head;
            int data=temp->getData();
            head=head->getNext();
            delete temp;
            return data;
        }
    }

};
int main(){
    Stack s;

    s.push(1);
    s.push(2);

    cout<<" POP: "<<s.pop()<<endl;
    cout<<" POP: "<<s.pop()<<endl;
    cout<<" POP: "<<s.pop()<<endl;
}
