/*
Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.
*/

//APPROACH 1

#include<bits/stdc++.h>

using namespace std;

void permute(int arr[], vector<int> &ds, vector<vector<int>> &ans,int map[], int n){
    if(ds.size() == n){
        ans.push_back(ds);                  //Time Complexity is O(n! * n)
        return;
    }

    for(int i=0;i<n;i++){
        if(!map[i]){
            ds.push_back(arr[i]);
            map[i] = 1;
            permute(arr,ds,ans,map,n);
            map[i] = 0;
            ds.pop_back();
        }
    }
}

int main(){
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(int);
    int map[n] = {0};
    vector<int> ds;
    vector<vector<int>> ans;

    permute(arr,ds,ans,map,n);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}