/* printing only one subsequence whose sum is k */ 
/* this code is only for learning, the concept and not intended to be effiecient */

#include<iostream>
#include<vector>

using namespace std;

bool subsequenceSum(int i,int s,int reqsum, int arr[],vector<int> &ds,int n){       //Time complexity is O(2^n)
    if(i==n){
        if(s == reqsum){
            for(auto it : ds)
                cout << it << " ";
            cout << endl;
            return true;
        }
        return false;
    }
    //Logic to take the value at particular index
    ds.push_back(arr[i]);
    s+= arr[i];
    if(subsequenceSum(i+1,s,reqsum,arr,ds,n) == true)
        return true;
    
    //Logic to not take the value at particular index
    s-= arr[i];
    ds.pop_back();
    if(subsequenceSum(i+1,s,reqsum,arr,ds,n) == true)
        return true;
    
    return false;
}

int main(){
    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(int);
    int reqsum = 2;
    vector<int> ds;
    subsequenceSum(0,0,reqsum,arr,ds,n);
    return 0;
}