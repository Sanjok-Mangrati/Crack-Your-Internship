//Swap alternate elements in an array

//These solution may not be optimised, it is just for learning the concept

#include<bits/stdc++.h>

using namespace std;

void swapAlt(int arr[], int n){
    for(int i=0;i<n;i+=2){
        if(i+1 < n){
            swap(arr[i],arr[i+1]);
        }
    }
}

int main(){
    int arr[5] = {2,4,7,9,1};
    swapAlt(arr,5);

    for(auto it : arr){
        cout << it << " ";
    }

    return 0;
}