#include<iostream>
using namespace std;
int swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int start=low;
    int end=high;
    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start < end){
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[low],&arr[end]);
    return end;
}
int quicksort(int arr[],int low,int high){
    if(low<high){
          int loc=partition(arr,low,high);
    quicksort(arr,low,loc-1);
    quicksort(arr,loc+1,high);
    }

}
int main(){
    int arr[]={45,8,44,1,4,77,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    cout<<"Print Array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
