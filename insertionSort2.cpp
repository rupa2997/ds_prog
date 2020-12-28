#include<iostream>
using namespace std;
int main(){
    int arr[]={6,2,1,3,0};
    int n,i,j,key;
    n=sizeof(arr)/sizeof(arr[0]);
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    for(int k=0;k<n;k++){
        cout<<arr[k]<<" ";
    }
}
