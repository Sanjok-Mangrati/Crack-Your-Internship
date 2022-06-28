/*
Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.
*/

//APPROACH 2

#include<bits/stdc++.h>

using namespace std;

void permute(int index, vector<int> &arr, vector<vector<int>> &ans){
    if(index == arr.size()){
        ans.push_back(arr);                     //Time Complexity is O(n! * n)
        return;
    }
    for(int i=index;i<arr.size();i++){
        swap(arr[index],arr[i]);
        permute(index+1,arr,ans);
        swap(arr[index],arr[i]);
    }
}

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;

    permute(0,arr,ans);

    for(int i=0;i<ans.size();i++){
        for(auto it : ans[i]){
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}