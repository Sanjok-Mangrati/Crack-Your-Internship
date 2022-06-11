/* counting number of subsequence whose sum is k */
/* this code is only for learning, the concept and not intended to be effiecient */ 

#include<iostream>
#include<vector>

using namespace std;

int subsequenceSum(int i,int s,int reqsum, int arr[],int n){       //Time complexity is O(2^n)
    if(i==n){
        if(s == reqsum){
            return 1;
        }
        return 0;
    }
    s+= arr[i];
    //Logic to take the value at particular index
    int l = subsequenceSum(i+1,s,reqsum,arr,n);
    
    s-= arr[i];
    //Logic to not take the value at particular index
    int r = subsequenceSum(i+1,s,reqsum,arr,n);
    
    return l+r;
}

int main(){
    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(int);
    int reqsum = 2;
    cout << "Number of subsequence whose sum is " << reqsum << " = " << subsequenceSum(0,0,reqsum,arr,n);
    return 0;
}