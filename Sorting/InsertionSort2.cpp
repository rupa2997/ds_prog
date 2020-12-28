#include<iostream>
using namespace std;
int main(){
    int a[] = {5, 2, 4, 6, 7, 1, 3};
    int i, j , temp;
    for(int i=1; i<7; i++){
        temp = a[i];
        for(j = i-1;  j>=0&&temp<a[j]; j--){
            a[j+1] = a[j];
        }
        a[j+1] = temp;
    }
    for(int i=0; i<7; i++){
        cout<<a[i]<<" ";
    }






return 0;
}
