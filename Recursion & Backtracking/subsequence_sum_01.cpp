/* printing all the subsequences whose sum is k */
/* this code is only for learning, the concept and not intended to be effiecient */

#include<iostream>
#include<vector>

using namespace std;

void subsequenceSum(int i,int s,int reqsum, int arr[],vector<int> &ds,int n){       //Time complexity is O(2^n)
    if(i==n){
        if(s == reqsum){
            for(auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    //Logic to take the value at particular index
    ds.push_back(arr[i]);
    s+= arr[i];
    subsequenceSum(i+1,s,reqsum,arr,ds,n);
    //Logic to not take the value at particular index
    s-= arr[i];
    ds.pop_back();
    subsequenceSum(i+1,s,reqsum,arr,ds,n);
    
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);
    int reqsum = 6;
    vector<int> ds;
    subsequenceSum(0,0,reqsum,arr,ds,n);
    return 0;
}