#include<iostream>>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(int arr[], int low, int high){
    int j = low-1;
    int pivot = arr[high];

    for(int i = low; i<= high-1; i++ ){

        if(arr[i] < pivot){
                j++;
            swap(arr[j], arr[i]);

        }
    }
    swap(& arr[j+1], & arr[high]);
    return j+1;

}

void QuickSort(int arr[], int low, int high){
    if(low<high){
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi-1);
        QuickSort(arr, pi+1, high);
    }
}

void print(int arr[], int s){
    for(int i=0; i<s; i++)
        cout<<arr[i]<<"  ";
}

int main(){
     int arr[] = {5, 4, 7, 2, 1};
     int n = 5;
     QuickSort(arr , 0 , n-1);
     print(arr, n);
     return 0;

}
