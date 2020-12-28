#include <iostream>
using namespace std;
class Que{
private:
    int front;
    int rear;
    int *store;
    int size1;
public:
    Que(int size1){
        this->size1=size1;
        front=rear=-1;
        store=new int[size1];
    }
    bool isEmpty(){

            return front==rear;
    }
    bool isFull(){
            return rear==(size1-1);
    }
        void push(int data){
        if(!isFull()){
            rear++;
            store[rear]=data;
        }else{
            cout<<"FULL!!!!"<<endl;
            //break;
            return;
        }
    }
    int pop(){
        if(!isEmpty()){
                front++;
            int data=store[front];
            return data;
        }else{
            cout<<"Empty!!!!"<<endl;
            //break;
            return -1;
        }
    }
    void reset(){
    front=rear=-1;
    }
};
class Stack{
private:
    Que *q1;
    Que *q2;
    int counter;
public:
    Stack(int size){
        q1=new Que(size);
        q2=new Que(size);
        counter=0;
    }
    void push(int data){
        if(!q1->isFull()){
                q1->push(data);
                counter++;
        }else{
        cout<<"FULL..."<<endl;
        }

    }
    int pop(){
        if(!q1->isEmpty() && q2->isEmpty()){
            while(counter!=1){
                q2->push(q1->pop());
                counter--;
            }
            int data=q1->pop();
            counter--;
            q1->reset();
            while(!q2->isEmpty()){
                q1->push(q2->pop());
                counter++;
            }
            q2->reset();
            return data;
        }else{
            cout<<"EMPTY"<<endl;
        }
    }
};
int main(){
    Stack s(3);
    s.push(1);
     s.push(2);
      s.push(3);
      cout<<"POPED ELE: "<<s.pop()<<endl;
      cout<<"POPED ELE: "<<s.pop()<<endl;
      cout<<"POPED ELE: "<<s.pop()<<endl;
      cout<<"POPED ELE: "<<s.pop()<<endl;
}
