#include<iostream>
using namespace std;
class Que{
private:
    int qre;
    int qfr;
    int size1;
    int *store;
public:
    Que(int size1){
        this->size1=size1;
        qre=-1;
        qfr=-1;
        store=new int[size1];
    }
    void enQ(int data){
        if(qfr==0 && qre==(size1-1) || qfr==(qre+1)){
            cout<<" OVERFLOW "<<endl;
            return;
        }
        if(qfr==-1){
            qfr=qre=0;
        }else if(qre==(size1-1)){
            qre=0;
        }else{
            qre=qre+1;
        }
        store[qre]=data;
    }

    void deQ(){
        if(qfr==-1){
            cout<<"UNDERFLOW "<<endl;
            return;
        }
        cout<<"DEQUE ELE: "<<store[qfr]<<endl;
        if(qfr==(size1-1)){
            qfr=0;
        }else if(qfr==qre){
            qfr=qre=-1;
        }else{
            qre=qre+1;
        }

    }

};
int main(){
    Que q(3);
    //q.enQ(2);
   q.deQ();
     //q.enQ(3);
    //q.deQ();
     q.enQ(4);
    q.deQ();
     //q.enQ(4);
}
