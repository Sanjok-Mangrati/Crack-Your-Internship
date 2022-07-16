/*
Given an integer array nums of length n where all the integers of nums 
are in the range [1, n] and each integer appears once or twice, 
return an array of all the integers that appears twice.
*/

//These solution may not be optimised, it is just for learning the concept

#include<bits/stdc++.h>

using namespace std;

/*

//Approach 1

void findDup(vector<int> &arr, vector<int> &ans){
    for(int i=1;i<arr.size();i++){
        if(arr[i-1] == arr[i]){
            ans.push_back(arr[i]);
        }
    }
}

int main(){
    vector<int> arr{1,1,2};
    vector<int> ans;

    if(arr.size() <= 1){
        cout << "{}" << endl;
        return 0;
    }

    sort(arr.begin(),arr.end());

    findDup(arr,ans);

    for(auto it : ans){
        cout << it << endl;
    }

    return 0;
}
*/

//Approach 2

void findDup(vector<int> &arr, vector<int> &map){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i] == arr[j]){
                int k = arr[i];
                map[k] = 1;
            }
        }
    }

    for(int i=0;i<map.size();i++){
        if(map[i] == 1){
            cout << i << endl;
        }
    }
}

int main(){
    vector<int> arr{4,3,2,7,8,2,3,1};
    vector<int> map(arr.size(),0);

    findDup(arr,map);

    return 0;
}