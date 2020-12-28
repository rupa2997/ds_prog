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
        int Size;
        Stack *s1;
        Stack *s2;
    public:
        Que(int Size){
            this->Size=Size;
             s1=new Stack(Size);
             s2=new Stack(Size);
            }
        void enQue(int data){
            s1->push(data);
        }
        int deq(){
            if(!s1->isEmpty() && s2->isEmpty()){
                while(!s1->isEmpty()){
                    s2->push(s1->pop());
                }
                int a=s2->pop();

                while(!s2->isEmpty()){
                    s1->push(s1->pop());
                }
            }else{
                cout<<"Que is empty"<<endl;
            }
        }

};
int main(){
    Que q(3);
    q.enQue(1);
    q.enQue(2);
    q.enQue(3);
    cout<<"pop:"<<q.deq()<<endl;
}
