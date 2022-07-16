/*
You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once.
There is a single integer value that is present in the array twice.
Your task is to find the duplicate integer value present in the array.
*/

//These solution may not be optimised, it is just for learning the concept

#include<iostream>
#include<vector>

using namespace std;

int findDup(vector<int> &arr){
    int ans = 0;

    //XOR ing all the elements
    for(int i=0;i<arr.size();i++){
        ans = ans ^ arr[i];
    }

    //XOR ing elements from 1 to N - 1
    for(int i=1;i<arr.size();i++){
        ans = ans ^ i;
    }

    return ans;
}

int main(){
    vector<int> arr{8,7,2,5,4,7,1,3,6};
    cout << "Duplicate element: " << findDup(arr) << endl;

    return 0;
}