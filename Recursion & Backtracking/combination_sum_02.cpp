/*
Given a collection of candidate numbers (candidates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.
*/

#include <bits/stdc++.h>
using namespace std;

void findCombination(int index, int target, int arr[], vector<vector<int>> &ans, vector<int> &ds, int n){
    //Base Case
    if(target == 0){                        //Time Complexity is (2^n * k)
        ans.push_back(ds);
        return;
    }
    for(int j=index;j<n;j++){
        if(j>index && arr[j] == arr[j-1]) continue; //Logic to not pick duplicate elements
        if(arr[j]>target) break;    //Stop if value we have is greater than target
        //Logic to take element at particular index 
        ds.push_back(arr[j]);
        findCombination(j+1,target-arr[j],arr,ans,ds,n);
        ds.pop_back();
    }
}

int main(){
    int arr[] = {10,1,2,7,6,1,5};
    int n = sizeof(arr)/sizeof(int);
    int target = 8;
    vector<vector<int>> ans;
    vector<int> ds;

    sort(arr,arr+n);

    findCombination(0,target,arr,ans,ds,n);

    for(int i=0; i<ans.size();i++){
        cout << "[ ";
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << ']';
        cout << endl;
    }

    return 0;

}