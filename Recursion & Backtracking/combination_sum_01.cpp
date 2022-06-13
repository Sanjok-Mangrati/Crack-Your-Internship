/*
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target.
You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times.
Two combinations are unique if the frequency of at least one of the chosen numbers is different.
*/

#include<iostream>
#include<vector>

using namespace std;

void findCombination(int i, int target, int arr[], vector<vector<int>> &ans, vector<int> &ds, int n){
    if(i == n){                         //Time Complexity is O(2^t * k)
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }
    if(arr[i] <= target){
        ds.push_back(arr[i]);
        findCombination(i,target-arr[i],arr,ans,ds,n);
        ds.pop_back();
    }
    findCombination(i+1,target,arr,ans,ds,n);
}

int main(){
    int arr[] = {2,3,5};
    int target = 8;
    int n = sizeof(arr)/sizeof(int);
    vector<vector<int>> ans;
    vector<int> ds;

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

/*
O(2^t * k) here k is the average length of combinations and 2^t 
because one element can be picked or not picked multiple times.
*/