#include<iostream>
using namespace std;

class Stack{

private:
    int size1;
    int top;
    int *store;
public:
    Stack(int size1){
        this->size1 = size1;
        top = -1;
        store = new int[size1];
    }
    ~Stack(){
        delete []store;
    }
    bool isEmpty(){
            return top == -1;
    }
    bool isFull(){
        return top == (size1-1);
    }
    void push(int data){
        if(!isFull()){
                top++;
           store[top] = data;
        }
    }
    int pop(){
        if(!isEmpty()){

            int  data = store[top];
             top--;

             return data;
        }
        cout<<"isEmpty"<<endl;

        return -1;
    }

    int Peek(){
        if(!isEmpty())
            return store[top];
    }
};

class Que{
private:
    Stack *s1;
    Stack *s2;

public:
    Que(int size){
        s1 = new Stack(size);
        s2 = new Stack(size);
    }
    void push(int data){
        s1->push(data);
    }
    int pop(){
        if(s1->isEmpty()&&s2->isEmpty()){
            cout<<"Que is Empty"<<endl;
        }

        if(s2->isEmpty()){
            while(!s1->isEmpty()){
                 s2->push(s1->pop());
            }
        }

        return s2->pop();

    }

};
int main(){

  Que q(3);
  q.push(1);
  q.push(2);
  q.push(3);
    q.push(5);
      q.push(6);
  cout<<q.pop()<<endl;
  cout<<q.pop()<<endl;
  cout<<q.pop()<<endl;
  cout<<q.pop()<<endl;
  cout<<q.pop()<<endl;
  cout<<q.pop()<<endl;
  cout<<q.pop()<<endl;
    q.push(7);
    q.push(8);
cout<<q.pop()<<endl;
cout<<q.pop()<<endl;

return 0;
}
