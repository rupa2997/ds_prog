#include<iostream>
using namespace std;
int main(){
     int arr[]={44,7,2,1,77};
    int n,i,k,j,min,temp,flag=0;
    n=sizeof(arr)/sizeof(arr[0]);
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
                flag=0;
            if(arr[j]>arr[j+1]){
                temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            flag=1;
            }
        }
        if(flag==1)
            break;
    }
    for(k=0;k<n;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
}
