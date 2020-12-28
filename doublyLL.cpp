#include<iostream>
using namespace std;
class Node
{
private:
    int data;
    Node* next;
    Node* prev;
public:
    Node(int data)
    {
        this->data=data;
        next=NULL;
        prev=NULL;
    }
    ~Node()
    {
        next=NULL;
        prev=NULL;
    }
    int getData()
    {
        return data;
    }
    Node* getNext()
    {
        return next;
    }
    Node* getPrev()
    {
        return prev;
    }
    void setNext(Node* next)
    {
        this->next=next;
    }
    void setPrev(Node* prev)
    {
        this->prev=prev;
    }
};

class LL{
     private:
        Node *head;
    public:
        LL()
        {
            head=NULL;
        }
        ~LL()
        {
            head=NULL;
        }
        void insertE(int data){
            Node* node=new Node(data);
            if(head==NULL){
                head=node;
            }else{
                Node* temp=head;
                while(temp->getNext()!=NULL){
                    temp=temp->getNext();
                }
                temp->setNext(node);
                node->setPrev(temp);
            }
        }

        void insertB(int data){
             Node* node=new Node(data);
             if(head==NULL){
                head=node;
            }else{
                 Node* temp=head;
                 node->setNext(temp);
                 head=node;
                 temp->setPrev(node);
            }
        }
        void insertMA(int tobe,int data){
            Node* node=new Node(data);
            if(head==NULL){
                cout<<"NOT FOUND"<<endl;
            }else{
                Node* temp=head;
                while(temp->getData()!=tobe){
                        if(temp->getNext()==NULL){
                            cout<<"NOT FOUND"<<endl;
                            break;
                        }
                     temp=temp->getNext();
                }
                if(temp->getNext()==NULL){
                    temp->setNext(node);
                    node->setPrev(temp);
                }else{
                    node->setNext(temp->getNext());
                    temp->setNext(node);

                }
            }
        }
        void insertMB(int tobe,int data){
             Node* node=new Node(data);
            if(head==NULL){
                cout<<"NOT FOUND"<<endl;
            }else{
                 Node* temp=head;
                while(temp->getData()!=tobe){
                        if(temp->getNext()){
                            cout<<"NOT FOUND"<<endl;
                            break;
                        }
                     temp=temp->getNext();
                }
                if(temp->getData()==tobe && temp!=head){
                    node->setNext(temp);
                    temp->getPrev()->setNext(node);
                }else{
                    node->setNext(temp);
                    head=node;
                }
            }
        }
        void DN(int data){
            if(head==NULL){
                cout<<"Empty Node"<<endl;
            }else{
                Node* temp=head;
                while(temp->getData()!=data){
                      if(temp->getNext()==NULL){
                            cout<<"NOT FOUND"<<endl;
                            break;
                        }
                     temp=temp->getNext();
                }
                if(temp->getData()==data && temp!=head){
                        if(temp->getNext()==NULL){
                             temp->getPrev()->setNext(NULL);
                             return;
                        }
                    temp->getPrev()->setNext(temp->getNext());
                    temp->getNext()->setPrev(temp->getPrev());
                }else{
                    head=head->getNext();
                    head->setPrev(NULL);
                }
            }

        }

        void DNA(int data){
            if(head==NULL){
                cout<<"Empty Node"<<endl;
            }else{
                Node* temp=head;
                while(temp->getData()!=data){
                      if(temp->getNext()==NULL){
                            cout<<"NOT FOUND"<<endl;
                            break;
                        }
                     temp=temp->getNext();
                }
                if(temp->getNext()==NULL){
                        cout<<"No ele present after given data to delete"<<endl;

                }else if(temp->getData()==data && temp->getNext()->getNext()!=NULL){
                    temp->setNext(temp->getNext()->getNext());
                    temp->getNext()->getNext()->setPrev(temp);

                }else{
                     temp->setNext(NULL);
                }
            }
        }

        void DNB(int data){
            if(head==NULL){
                cout<<"Empty Node"<<endl;
            }else{
                Node* temp=head;
                Node* pre=NULL;
                while(temp->getData()!=data){
                      if(temp->getNext()==NULL){
                            cout<<"NOT FOUND"<<endl;
                            break;
                        }
                        pre=temp;
                     temp=temp->getNext();
                }
                if(temp!=head && pre->getPrev()!=NULL ){

                temp->getPrev()->getPrev()->getNext()->setNext(temp);

                    temp->setPrev(temp->getPrev()->getPrev()->getNext());
                }else if(temp!=head && pre->getPrev()==NULL){
                    head=head->getNext();
                }else{
                    cout<<"No ele present before the given ele to delete"<<endl;
                    return;
                }
            }
        }
        void print(){
            Node* temp=head;
            while(temp->getNext()!=NULL){
                cout<<temp->getData()<<"->";
                 temp=temp->getNext();
            }
             cout<<temp->getData()<<endl;
        }
};
int main(){
    LL l1;
    l1.insertB(1);
    l1.insertE(2);
    l1.insertMA(2,3);
    l1.insertMA(1,4);
     l1.insertMB(1,5);
      l1.print();
      l1.DNB(3);
      l1.print();
      l1.DNB(5);
       l1.print();
      l1.insertMB(5,99);
      l1.print();
     //l1.DN(5);


    return 0;
}
