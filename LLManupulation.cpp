#include<iostream>
using namespace std;
class Node{
    private:
         int age;
        string name;
        Node *next;

    public:
        Node(string name,int age){
            this->age=age;
            this->name=name;
            next=NULL;
        }
       void setNext(Node* next){
            this->next=next;
       }
       Node* getNext(){
            return next;
       }

        int getAge(){
            return age;
        }
        void setAge(int age){
            this->age=age;
        }
        string getName(){
            return name;
        }
        void setName(string name){
            this->name=name;
        }
};
class LL{
private:
   Node* head;
public:
    LL(){
        head=NULL;
    }
    void insertB(string name,int age){
        Node* node= new Node(name,age);

        if(head==NULL){
            head=node;
        }else{
            Node* temp=head;
            Node* prev=NULL;
            if(temp->getAge()>=age){
                node->setNext(head);
                head=node;
            }else{
                while(temp->getAge()<age){
                    if(temp->getNext()==NULL){
                        //temp->setNext(node);
                        prev=temp;
                        break;
                    }else{
                        prev=temp;
                        temp=temp->getNext();
                    }
                }

                if(prev!=NULL){
                    prev->setNext(node);
                }else{
                    node->setNext(temp);
                }

            }
        }
    }

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->getName()<<" "<<temp->getAge()<<endl;
            temp=temp->getNext();
        }
    }
};
int main(){
    LL l1;
    l1.insertB("Rupali",30);
    l1.insertB("Sonali",20);
     l1.insertB("Pallavi",45);
     l1.insertB("Sharddha",10);
   l1.display();
    return 0;
}
