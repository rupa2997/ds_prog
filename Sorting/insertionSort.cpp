#include<iostream>
using namespace std;
int main(){
    int a[] = {5, 2, 4, 6, 7, 1, 3};
    int i, j , temp;
    for(int i=1; i<7; i++){
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j = j-1;

        }
        a[j+1] = temp;
        cout<<endl;
    }
    for(int i=0; i<7; i++){
        cout<<a[i]<<" ";
    }






return 0;
}
