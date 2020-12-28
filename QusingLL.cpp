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
class Que{
private:
    Node* head;
    Node* tail;
public:
    Que(){
        head=NULL;
        tail=NULL;
    }
    void enQ(int data){
        Node* node=new Node(data);
        if(head==NULL){
            head=node;
            tail=node;
        }else{
            Node* temp=tail;
            tail->setNext(node);
            tail=node;

        }
    }
    int deQ(){
        if(head==NULL){
            cout<<"EMPTY QUEUE!!!!!"<<endl;
            return -1;
        }
        else if(head==tail){
            Node* temp=head;
            int data=temp->getData();
            head=tail=NULL;
            return data;
        }else{
            Node* temp=head;
            int data=temp->getData();
            head=head->getNext();
            delete temp;
            return data;
        }
    }

      void rev(){
        Node* temp=head;
        revL(temp);
    }

    void revL(Node* temp){
        if(temp->getNext()!=NULL){
            revL(temp->getNext());
        }
        cout<<temp->getData()<<" ";
    }
};
int main(){
    Que q;
    q.enQ(1);
     q.enQ(2);
      q.enQ(3);
       q.enQ(4);
        q.rev();
    //cout<<"POPED ELE!!!!!!!"<<q.deQ()<<endl;
     //cout<<"POPED ELE!!!!!!!"<<q.deQ()<<endl;
      //cout<<"POPED ELE!!!!!!!"<<q.deQ()<<endl;
}
