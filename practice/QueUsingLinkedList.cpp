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
class Queue{
   private:
       Node<T> *head, *tail;
   public:
        Queue(){
            head = tail = NULL;
        }
        void enQue(T data){
            Node<T> *node = new Node<T>();
            if(head == NULL){
                head = node;
                tail = node;
            cout<<"enque "<<endl;

            }
            else{
                tail->setNext(node);
                tail = node;
                cout<<"enque else"<<endl;

            }
        }
        T deQue(){
            if(head == NULL){
                cout<<"Que is empty"<<endl;
                return 2;


            }

else{            T data = head->getData();
            cout<<data<<endl;
            head = head->getNext();
            return data;}
        }
};

int main(){
    Queue<int> s;
    s.enQue(5);
    s.enQue(2);
    s.enQue(1);
    s.enQue(3);
    s.enQue(4);
    s.enQue(8);

    cout<<s.deQue()<<endl;
    cout<<s.deQue()<<endl;
    cout<<s.deQue()<<endl;

    cout<<s.deQue()<<endl;
    cout<<s.deQue()<<endl;
    cout<<s.deQue()<<endl;
    cout<<s.deQue()<<endl;




}

