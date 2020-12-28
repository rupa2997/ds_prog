#include<iostream>
using namespace std;
class Stack{
 private:
     int top;
     int Size;
     int *store;
 public:
     Stack(int Size){
        this->Size=Size;
        top=-1;
        store=new int[Size];
     }
    bool isFull(){
        return top==(Size-1);
    }
    bool isEmpty(){
        return top==-1;
    }
    void push(int data){
        if(!isFull()){
            top++;
            store[top]=data;
        }else{
            cout<<"Que is full"<<endl;
        }
    }

    int pop(){
        if(!isEmpty()){
            int x=store[top];
            top--;
            return x;
        }
        else{
            cout<<"Que is Empty"<<endl;
        }
        return -1;
    }

};
class Que{
private:
    Stack *s1;
    Stack *s2;
    int Size;
public:
    Que(int Size){
        this->Size=Size;
        s1=new Stack(Size);
        s2=new Stack(Size);
    }
    void enQ(int data){
        s1->push(data);
    }
    int deQ(){
        if(s1->isEmpty()){
            cout<<"Empty Que!!!!"<<endl;
            return -1;
        }else{
            while(!s1->isEmpty())
            {
                s2->push(s1->pop());
            }
            int data=s2->pop();
            while(!s2->isEmpty()){
                s1->push(s2->pop());
            }
            return data;
        }
    }
};
int main(){
   Que q(3);
   q.enQ(1);
   q.enQ(2);
    q.enQ(3);
     q.enQ(4);
   cout<<" POPED ELE: "<<q.deQ()<<endl;
   cout<<" POPED ELE: "<<q.deQ()<<endl;
   cout<<" POPED ELE: "<<q.deQ()<<endl;
   cout<<" POPED ELE: "<<q.deQ()<<endl;


}
