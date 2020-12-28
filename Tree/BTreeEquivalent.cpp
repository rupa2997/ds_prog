//Btree equivalent

#include<iostream>
using namespace std;
class Node
{
    private:
        int data;
        Node* left;
        Node* right;
    public:
        Node()
        {
            left=right=NULL;
            data=0;
        }
        Node(int data)
        {
            this->data=data;
            left=right=NULL;
        }
        ~Node()
        {
            left=right=NULL;
        }
        int getData()
        {
            return data;
        }
        void setLeft(Node* left)
        {
            this->left=left;
        }
        Node* getLeft()
        {
            return left;
        }
        void setRight(Node* right)
        {
            this->right=right;
        }
        Node* getRight()
        {
            return right;
        }
};
class Btree
{
    private:
        Node* root1;
    public:
        Btree()
        {
            root1=NULL;
        }
        Node* insert()
        {
            Node* root=NULL;
            int data;
            cin>>data;
            while(1)
            {
                if(data==-1)
                    break;
                root=insert(root,data);
                cin>>data;
            }
            return root;
        }
        Node* insert(Node* root,int data)
        {

            if(root==NULL)
            {
                Node *node=new Node(data);
                return node;
            }
            if(root->getData() < data)
              {
                  root->setRight(insert(root->getRight(),data));
                  return root;
              }
            else
            {
                root->setLeft(insert(root->getLeft(),data));
                return root;
            }
        }
        int compare(Node* node1,Node* node2)
        {
            if(node1==NULL && node2==NULL)
            {
                return 1;
            }
            if(node1!=NULL && node2!=NULL)
            {
                return(compare(node1->getLeft(),node2->getLeft()) && compare(node1->getRight(),node2->getRight()));
            }
            return 0;
        }
        int depthOT(Node* root)
        {
            if(root==NULL)
            {
                return 0;
            }
            else
            {
                int ld=depthOT(root->getLeft());
                int rd=depthOT(root->getRight());
                if(ld>rd)
                {
                    return (ld+1);
                }
                else
                {
                    return (rd+1);
                }
            }
        }

};
int main()
{
    Btree b;
    int no;
    cin>>no;
    int a;
    Node *node1=b.insert();
    for(int i=0;i<no-1;i++)
    {
        Node *node2=b.insert();
        int de=(b.depthOT(node1)-b.depthOT(node2));
        if(de==-1 || de==1)
        {
            de=1;
        }
        if(b.compare(node1,node2))
        {
            cout<<"YES "<<de<<endl;
        }
        else
        {
            cout<<"NO "<<de<<endl;
        }
    }
    return 0;
}
