#include<iostream>
#include<cstring>
using namespace std;
class Node
{
    private:
        int data;
        Node* left;
        Node* right;
    public:
        Node(int d)
        {
            data=d;
            left=right=NULL;
        }
        int getdata()
        {
            return data;
        }
        Node* getleft()
        {
            return left;
        }
        Node* getright()
        {
            return right;
        }
        void setleft(Node* l)
        {
            left=l;
        }
        void setright(Node* r)
        {
            right=r;
        }

};
class Tree
{
    private:
        Node* root;
    public:
        Tree()
        {
            root=NULL;
        }
        void insertT(int d)
        {
            Node* nd=new Node(d);
            if(nd==NULL)
            {
                return;
            }
            if(root==NULL)
            {
                root=nd;
            }
            else{
                    Node* temp=root;
                    while(1)
                    {
                        if(temp->getdata()>=d)
                        {
                            if(temp->getleft()==NULL)
                            {
                                temp->setleft(nd);
                                break;
                            }
                            temp=temp->getleft();
                            continue;
                        }
                        else{
                                if(temp->getright()==NULL)
                                {
                                    temp->setright(nd);
                                    break;
                                }
                                temp=temp->getright();
                                continue;
                        }
                    }
            }
        }
       void Path(int s)
       {
           string str;
           Node* temp=root;
           if(s==temp->getdata())
           {
              str="Root ";
           }
           else{
                    str="Root ";
                    while(temp!=NULL && temp->getdata()!=s)
                    {
                        if(s < temp->getdata())
                        {
                            temp=temp->getleft();
                            str=str+"L ";
                        }
                        else{
                                temp=temp->getright();
                                str=str+"R ";
                        }
                    }
                }
            if(temp==NULL)
            {
                cout<<"Not Found";
            }
            else{
                cout<<str;
            }
       }
       Node* getroot()
       {
           return root;
       }

};

int main()
{
    Tree T;
    int n=0,d,s;
    while(1)
    {
        cin>>d;
        if(d==-1)
        {
           break;
        }
        T.insertT(d);

}
    cin>>n;
    if(T.getroot()==NULL)
    {
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        cin>>s;
        T.Path(s);
        cout<<endl;

    }
    return 0;
}
