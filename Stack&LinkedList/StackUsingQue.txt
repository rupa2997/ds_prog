#include<iostream>
using namespace std;
class Que{
    private:
        int size1;
        int qfront;
        int qrare;
        int *store;

    public:
        Que(int size1){
           this->size1 = size1;
           qfront = qrare = -1;
           store = new int[size1];
        }
        ~Que(){
            delete []store;
        }
        bool isEmpty(){
            return qfront == qrare;
        }
        bool isFull(){
            return qrare == size1-1;
        }
        void enQue(int data){
            if(!isFull()){
                qrare++;
                store[qrare] = data;
            }
        }
        int deQue(){
            if(!isEmpty()){
                qfront++;
                return store[qfront];
            }
        }
        void reset(){
            qfront = qrare = -1;
        }
};

class Stack{
    private:
        Que *q1;
        Que *q2;
        int curSize;


    public:
        Stack(int size1){
            q1 = new Que(size1);
            q2 = new Que(size1);
            curSize = 0;
        }
        void push(int data){
            if(!q1->isFull()){
                q1->enQue(data);
                curSize++;
            }
        }
        int pop(){
            if(q2->isEmpty()){
                while(curSize != 1)
                {
                    q2->enQue(q1->deQue());
                    curSize--;

                }

                int x = q1->deQue();
                curSize--;
                q1->reset();
                while(!q2->isEmpty()){
                    q1->enQue(q2->deQue());
                    curSize++;
                }
                q2->reset();
                return x;
            }
        }
};
int main(){

    Stack s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;


    return 0;
}
