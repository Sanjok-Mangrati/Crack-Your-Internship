/*Given a list arr of N integers, print sums of all subsets in it, in sorted order*/

#include<bits/stdc++.h>

using namespace std;

void subsetSum(int i,int sum, vector<int> &sums, int arr[], int n){
    if(i==n){                           //Time Complexity is O(2^n + 2^nLog(2^n))
        sums.push_back(sum);               //2^nLog(2^n) for sorting the array
        return;
    }
    //Pick
    subsetSum(i+1,sum+arr[i],sums,arr,n);
    //Not Pick
    subsetSum(i+1,sum,sums,arr,n);
}

int main(){
    int arr[] = {5,2,1};
    int n = sizeof(arr)/sizeof(int);
    vector<int> ds;
    vector<int> sums;

    subsetSum(0,0,sums,arr,n);

    sort(sums.begin(),sums.end());

    for(auto it : sums){
        cout << it << endl;
    }

    return 0;
}