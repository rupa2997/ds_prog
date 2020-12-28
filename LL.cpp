#include<iostream>
using namespace std;
class Node{
    private:

        Node *next;
        int data;
    public:
        Node(int data){
            this->data=data;
            next=NULL;
        }
       void setNext(Node* next){
            this->next=next;
       }
       Node* getNext(){
            return next;
       }
        void setData(int data){
            this->data=data;
        }
        int getData(){
            return data;
        }
};

class LL{
private:
    Node *head;
public:
    LL(){
        head=NULL;
    }
    void insertE(int data){
        Node* node=new Node(data);
        if(head==NULL){
            head=node;
        }else{
            Node* temp=head;
            if(temp->getNext()==NULL){
                temp->setNext(node);
            }else{
                while(temp->getNext()!=NULL){
                    temp=temp->getNext();
                }
                temp->setNext(node);

            }

        }
    }

    void insertB(int data){
        Node* node=new Node(data);
        if(head==NULL){
            head=node;
        }else{
            node->setNext(head);
            head=node;
        }
    }

    void insertAD(int a,int data){
        Node* node=new Node(data);
         if(head==NULL){
            head=node;
        }else{
            Node* temp=head;
            while(temp->getData()!=a){
                temp=temp->getNext();
            }
            if(temp->getNext()==NULL){
                temp->setNext(node);
            }else{
                node->setNext(temp->getNext());
                temp->setNext(node);
            }
        }

    }

    void insertBD(int b,int data){
        Node* node=new Node(data);
         if(head==NULL){
            head=node;
        }else{
            Node* temp=head;
            Node* prev=NULL;
            if(temp->getData()==b){
                node->setNext(temp);
                head=node;
            }else{
                while(temp->getNext()->getData()!=b){
                    temp=temp->getNext();
                }
                prev=temp;
                temp=temp->getNext();
                node->setNext(temp);
                prev->setNext(node);

            }
        }

    }

    void DN(int data){
        Node* temp=head;
        Node* prev=NULL;
        if(temp->getData()==data){
            if(temp->getNext()==NULL){
                head=NULL;
            }else{
                head=temp->getNext();
                delete temp;

            }
        }else{
            while(temp->getData()!=data){
                    prev=temp;
                temp=temp->getNext();

            }
            if(temp->getNext()==NULL){
                prev->setNext(NULL);
                delete temp;
            }else{
                prev->setNext(temp->getNext());
                delete temp;
            }
        }
    }

    void DNA(int data){
        Node* temp=head;
        Node* prev=NULL;
        while(temp->getData()!=data){
            temp=temp->getNext();
        }
        prev=temp;
        temp=temp->getNext();
        if(temp->getNext()==NULL){
            prev->setNext(NULL);
        }else{
            prev->setNext(temp->getNext());
            delete temp;
        }
    }

    void DNB(int data){
        Node* temp=head;
        Node* prev=NULL;
       while(temp->getNext()->getData()!=data){
            prev=temp;
            temp=temp->getNext();
       }

       if(prev==NULL && temp==head){
        head=head->getNext();
        delete temp;
       }else{
           prev->setNext(temp->getNext());
           delete temp;

       }

    }

    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->getData()<<" ";
            temp=temp->getNext();
        }
        cout<<endl;
    }
     void Fprint(){
        Node* temp=head;
        while(temp->getNext()!=NULL){
            cout<<temp->getData()<<"->";
            temp=temp->getNext();
        }
        cout<<temp->getData();
        cout<<endl;
    }


};
int main(){
    LL l;
    l.insertB(3);
    l.insertB(4);
    l.insertB(5);
     l.insertE(2);
     l.insertAD(4,1);
      l.insertBD(3,6);
       l.insertBD(6,7);
       l.insertAD(7,8);
        l.Fprint();
       l.DN(1);
    l.Fprint();
       l.DN(5);
     l.Fprint();
            l.DNA(3);
     l.Fprint();
        l.DNB(7);
     l.Fprint();
       l.insertBD(7,11);
       //l.print();
        l.Fprint();

}
