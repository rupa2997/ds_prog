#include<iostream>
using namespace std;
class Stack{
private:
    int top;
    char *store;
    int size1;
public:
    Stack(int size1){
        this->size1=size1;
        top=-1;
        store=new char[size1];
    }
    int isEmpty(){
        if(top==-1)
            return 1;
        return 0;
    }
    int isFull(){
        if(top==(size1-1))
            return 1;
        return 0;
    }
    void push(char str){
        if(!isFull()){
            top++;
            store[top]=str;
        }else{

        cout<<"full";
        }
    }

    char pop(){
    if(!isEmpty()){
        int str=store[top];
        top--;
        return str;
    }else{
        cout<<"Empty";
    }
    }
    void compare(string str){
        int countc=0,counto=0;
        int n=str.length();
        for(int i=0;i<n;i++){
            if(str[i]=='{' || str[i]=='(' || str[i]=='['){
                push(str[i]);
                counto++;
               }else if(str[i]=='}' && store[top]=='{'){
                    counto--;
                    pop();
                }else if(str[i]==')' && store[top]=='('){
                    counto--;
                    pop();
                }else if(str[i]==']' && store[top]=='['){
                     counto--;
                    pop();
                }else if(str[i]=='}' || str[i]==')' || str[i]==']'){
                    countc++;
                }
                //i++;

        }
        if(countc>counto){
            cout<<"TOO many closing";
        }else if(countc<counto){
             cout<<"TOO many Opening";
        }else if(isEmpty() && (counto==0)){
            cout<<"VALID";
        }else{
            cout<<"MISMATCH";
        }
    }
};

int main(){
    Stack s(6);
    cout<<"Enter exp: "<<endl;
    string str;
    cin>>str;
    s.compare(str);
}
