
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
    Node* getprev()
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

class Dlist
{
    private:
        Node *head;
    public:
        Dlist()
        {
            head=NULL;
        }
        ~Dlist()
        {
            head=NULL;
        }
        void insertEnd(int data)
        {
            Node *node=new Node(data);
            if(head==NULL)
            {
                head=node;
            }
            else
            {
                Node* temp=head;
                while(temp->getNext()!=NULL)
                {
                    temp=temp->getNext();
                }
                temp->setNext(node);
                node->setPrev(temp);
            }
        }
        void insertBefore(int data)
        {
            Node *node=new Node(data);
            if(head==NULL)
            {
                head=node;
            }
            else
            {
                Node *temp=head;
                head=node;
                node->setNext(temp);
                temp->setPrev(node);
            }
        }
        void insertMA(int tobe,int data)
        {
            Node *node=new Node(data);
            Node *temp=head;
            if(head==NULL)
            {
                cout<<"no data"<<endl;
            }
            else
            {
                while(temp->getData()!=tobe)
                {
                    if(temp->getNext()==NULL)
                    {
                        cout<<"not found "<<tobe<<endl;
                        break;
                    }
                    temp=temp->getNext();
                }
                if(temp->getData()==tobe)
                {
                    node->setNext(temp->getNext());
                    temp->setNext(node);
                    // node->setPrev(temp);
                    // temp->getNext()->setPrev(node);
                }

            }
        }
        void deleteNode(int data)
        {
            Node* temp=head;
            if(head==NULL)
            {
                cout<<"No data"<<endl;
            }
            else if(head->getData()==data)
            {
                head=head->getNext();
            }
            else
            {
                Node *pre=head;
                while(temp->getData()!=data)
                {
                    pre=temp;
                    if(temp->getNext()==NULL)
                    {
                        cout<<"node not found"<<endl;
                        break;
                    }
                    temp=temp->getNext();
                }
                if(temp->getData()==data)
                {
                    pre->setNext(temp->getNext());
                    temp->getNext()->setPrev(pre);
                }
            }
        }
        void deleteA(int data)
        {
            if(head==NULL)
            {
                cout<<"No data"<<endl;
            }
            else
            {
                Node *temp=head;
                Node *pre;
                while(temp->getData()!=data)// && temp->getNext()!=NULL)
                {
                    if(temp->getNext()==NULL)
                    {
                        cout<<"no data found"<<endl;
                        break;
                    }
                    temp=temp->getNext();
                }
                if(temp->getData()==data) //&&
                {
                    if(temp->getNext()!=NULL)
                    {
                        temp->setNext(temp->getNext()->getNext());
                        //temp->getNext()->getNext()->setPrev(temp);
                    }
                    else
                    {
                    cout<<"no deletion possible after ending node "<<endl;
                    }
                }
            }
        }
        void insertMB(int tobe,int data)
        {
            Node *node=new Node(data);
            Node *temp=head;
            if(head==NULL)
            {
                cout<<"no data"<<endl;
            }
            else
            {
                while(temp->getData()!=tobe)
                {
                    temp=temp->getNext();
                    if(temp->getNext()==NULL)
                    {
                        cout<<"data not found "<<endl;
                        break;
                    }
                    if(temp->getData()==tobe)
                    {
                        node->setNext(temp);
                        temp->getprev()->setNext(node);
                    }
                }
            }
        }
        void print()
        {
            Node *temp=head;
            while(temp->getNext()!=NULL)
            {
                cout<<temp->getData()<<"->";
                temp=temp->getNext();
            }
            cout<<temp->getData();
            cout<<endl;
        }
};
int main()
{
    Dlist d;
    d.insertEnd(10);
    d.insertEnd(20);
    d.insertEnd(30);
    d.insertEnd(40);
    d.insertEnd(50);
    d.insertBefore(5);

    d.print();
    return 0;
}
