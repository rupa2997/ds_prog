#include<iostream>
using namespace std;
int main(){
    int arr[]={4,7,2,1,77};
    int n,i,k,min,temp;;
    n=sizeof(arr)/sizeof(arr[0]);
    for(i=0;i<n;i++){
        min=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
        for(k=0;k<n;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
}
