#include<iostream>
#include<vector>

using namespace std;

//This function also takes Null( {} ) set as a subsequence
void subsequence(int i, vector<int> &ds, int arr[],int n){          //Time Complexity is near about O(2^n)
    //Base Case                                                     //Space Complexity is O(n)
    if(i==n){
        for(auto it : ds)
            cout << it << " ";
        if(ds.size() == 0)
            cout << "{}";
        cout << endl;
        return;
    }
    //Logic to Take the value at particular index
    ds.push_back(arr[i]);
    subsequence(i+1,ds,arr,n);

    //Logic to Not Take the value at particular index
    ds.pop_back();
    subsequence(i+1,ds,arr,n);
}

int main(){
    int arr[] = {3,1,2};
    int n = sizeof(arr)/sizeof(int);
    vector<int> ds;
    subsequence(0,ds,arr,n);
    return 0;
}
