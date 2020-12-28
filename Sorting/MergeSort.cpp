#include<iostream>
using namespace std;

void Merge(int arr[], int low, int m, int high){
    int n1 = m - low+1;
    int n2 = high - m;

    int L[n1], R[n2];

    for(int i=0; i<n1; i++)
        L[i] = arr[low+i];
    for(int j=0; j<n2; j++)
        R[j] = arr[m+1+j];

    int i=0, j=0;
    int k = low;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void MergeSort(int arr[], int low, int high){
    if(low>=high){
        return;
    }
    int m = (low+high-1)/2;
    MergeSort(arr, low, m);
    MergeSort(arr, m+1, high);
    Merge(arr, low, m, high);

}
void print(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}
int main(){
     int arr[] = {5, 4, 7, 2, 1};
        int n = 5;
        MergeSort(arr, 0, 4 );
        print(arr, 5);
        return 0;
}
