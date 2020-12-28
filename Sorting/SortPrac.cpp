#include<iostream>
using namespace std;

void swap(int *a, int *b){
int temp = *a;
*a = *b;
*b = temp;
}
int partion(int a[], int lb, int ub){

int pi = a[lb];
int s = lb;
int e = ub;

while(s<e){
    while(a[s] <= pi){
        s++;
    }
    while(a[e] > pi){
        e--;
    }
    if(s<e){
        swap(a[s], a[e]);
    }
}
swap(a[lb], a[e]);
return e;

}


void QuickSort(int arr[], int lb, int ub){

if(lb<ub){
    int pi = partion(arr, lb, ub);
    QuickSort(arr, lb, pi-1);
    QuickSort(arr, pi+1, ub);
}
}

int main(){

int arr[] = {7, 2, 4, 3, 1, 8, 6, 5};
int n = 8;

QuickSort(arr, 0, 7);

for(int i=0; i<n; i++){
    cout<<arr[i]<<"  ";
}

return 0;
}
