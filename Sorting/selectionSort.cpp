#include<iostream>
using namespace std;
int main(){
    int a[] = {5, 2, 4, 6, 7, 1, 3};
    int i, j , mini;
   for(i=0; i<6; i++){
    mini = i;
    for(j = i+1; j<7; j++){
        if(a[j]<a[mini]){
            mini = j;
        }
    }
    int k = a[mini];
        a[mini] = a[i];
        a[i] = k;
   }

   for(int j=0; j<7; j++){
    cout<<a[j]<<" ";
   }
return 0;
}

