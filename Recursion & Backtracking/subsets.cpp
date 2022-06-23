/* 
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
*/

#include <bits/stdc++.h>

using namespace std;

void subsets(int index, int arr[], vector<int> &ds, vector<vector<int>> &ans, int n){
    ans.push_back(ds);                                  //Time complexity is O(2^n * K)

    for(int i=index;i<n;i++){
        if(i>index && arr[i] == arr[i-1]) continue;
        
        ds.push_back(arr[i]);
        subsets(i+1,arr,ds,ans,n);
        ds.pop_back();
    }
}

int main(){
    int arr[] = {1,2,2};
    int n = sizeof(arr)/sizeof(int);
    vector<int> ds;
    vector<vector<int>> ans;

    sort(arr,arr+n);

    subsets(0,arr,ds,ans,n);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}