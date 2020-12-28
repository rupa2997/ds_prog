#include <iostream>

using namespace std;

class Stack{

    private:
        int size;
        int top;
        int *store;
    public:
        Stack(int size){
            this->size = size;
            top = 0;
            store = new int[size];
        }
        ~Stack(){
            delete [] store;
        }
        int isEmpty(){
            if(top == 0)
                return 1;
            else
                return 0;
        }
        int isFull(){
            if(top == size)
                return 1;
            return 0;
        }
        void push(int data){
            if(!isFull()){

                store[top] = data;
                 top++;
            }
            else{
                cout<<"Stack is Full"<<endl;
            }
        }
        int pop(){
            if(!isEmpty()){
                 top--;
                int data = store[top];

                return data;
            }
            else{
                cout<<"Stack is empty"<<endl;
            }
        }
        void display(){
            for(int i=0; i<size; i++){
                cout<<store[i]<<" ";
            }
        }
};

int main(){

  Stack s(3);
  s.display();
  cout<<endl;

  s.push(2);
  s.push(3);

  s.display();
   cout<<endl;

  s.push(1);
    s.display();
 cout<<endl;
   s.push(5);
  cout<<"poped element - "<<s.pop()<<"  "<<endl;


cout<<"poped element - "<<s.pop()<<"  "<<endl;

  cout<<"poped element - "<<s.pop()<<"  "<<endl;
    cout<<"poped element - "<<s.pop()<<"  "<<endl;
      cout<<"poped element - "<<s.pop()<<"  "<<endl;
s.display();

  return 0;
};


















