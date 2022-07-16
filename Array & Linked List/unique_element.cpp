/*
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.
*/

//These solution may not be optimised, it is just for learning the concept

#include<bits/stdc++.h>

using namespace std;

int findUnique(int arr[], int size){
    int ans = 0;

    for(int i=0;i<size;i++)
        ans = ans ^ arr[i];
    
    return ans;
}

int main(){

    int arr[] = {1,2,3,12,3,2,1,12,4,15,9,9,15};
    int n = 13;
    
    cout << "Unique element is " << findUnique(arr,n) << endl;

    return 0;
}