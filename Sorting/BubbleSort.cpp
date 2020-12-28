#include<iostream>
using namespace std;
int main(){
    int a[] = {4, 3, 5, 2};
    int n = 4;
    for(int i=0; i<n-1; i++){

        for(int j=0; j<n-1
        -i; j++){
            if(a[j] > a[j+1]){
                int k = a[j+1];
                a[j+1] = a[j];
                a[j] = k;
            }
        }

    }

   for(int j=0; j<4; j++){
    cout<<a[j]<<" ";
   }
return 0;
}


