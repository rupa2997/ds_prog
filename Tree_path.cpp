#include<iostream>
using namespace std;
int arr1[10],arr2[10],j=0,i=0;
class Node{
private:
    int data;
    Node *left,*right;
public:
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
    void setLeft(Node* l){
        left=l;
    }
    void setRight(Node* r){
        right=r;
    }
    Node* getLeft(){
        return left;
    }
    Node* getRight(){
        return right;
    }
    int getData(){
        return data;
    }
    void setData(){
        this->data=data;
    }


};
class Tree{
private:
    Node* root;
public:
    Tree(){
        root=NULL;
    }
    void insertBST(int data){
        Node* node=new Node(data);
        if(root==NULL){
            root=node;
        }else{
            Node* temp=root;
            while(1){
                 if(temp->getData()>=data){
                    if(temp->getLeft()==NULL){
                        temp->setLeft(node);
                        break;
                    }else{
                        temp=temp->getLeft();
                        continue;
                    }
                }else{
                    if(temp->getRight()==NULL){
                        temp->setRight(node);
                        break;
                    }else{
                        temp=temp->getRight();
                        continue;
                    }
                }
            }
        }
    }

        Node* getRoot(){
            return root;
        }

        int inorderB(Node* temp1){
            //Node* temp=root1;
            if(temp1==NULL){
                return 0;
            }else{
                inorderB(temp1->getLeft());
                arr1[i]=temp1->getData();
                i++;
                inorderB(temp1->getRight());
            }
        }
          int preorderB(Node* temp1){
            //Node* temp=root1;
            if(temp1==NULL){
                return 0;
            }else{
                arr2[j]=temp1->getData();
                j++;
                 preorderB(temp1->getLeft());
                preorderB(temp1->getRight());
            }
        }
        void treeP(int d){
            string str="";
            Node* temp=root;
            if(temp->getData()==d){
                str="Root ";
            }else{
                 str="Root ";
                while(temp->getData()!=d){
                        if(temp->getData()>d){
                            str=str+"L ";
                            temp=temp->getLeft();
                        }else{
                            str=str+"R ";
                            temp=temp->getRight();
                        }

                }
                if(temp==NULL){
                    cout<<"NOT FOUND:"<<endl;
                }else{
                    cout<<str<<endl;
                }

            }
        }

        int depth(Node* p){
            int h;
            if(p==NULL){
                return 0;
            }
            int left=depth(p->getLeft());
            int right=depth(p->getRight());
            if(left>right){
                h=1+left;
            }else{
                h=1+right;
            }
            return h;
        }
};


int main(){
    Tree t;
    int d,n,counter=0;;
    while(1){
        cin>>d;
        if(d==-1){
            break;
        }else{
                t.insertBST(d);
                counter++;
        }
    }
    t.inorderB(t.getRoot());
     cout<<"=================================="<<endl;
      cout<<"============inOrder======"<<endl;
    for(i=0;i<counter;i++){
        cout<<arr1[i]<<" ";
    }
    t.preorderB(t.getRoot());
     cout<<"=============preOrder========="<<endl;
      for(j=0;j<counter;j++){
        cout<<arr2[j]<<" ";
    }
    cout<<"=================================="<<endl;
    //t.compare();
     for(j=0;j<counter;j++){
            if(arr1[j]==arr2[j]){
                cout<<j<<" "<<arr2[j]<<endl;
            }
    }
    cout<<"Height of the tree"<<endl;
    int h=t.depth(t.getRoot());
    cout<<h<<endl;
    cout<<"ENter data u want to search path"<<endl;
    cin>>n;
    t.treeP(n);
}
