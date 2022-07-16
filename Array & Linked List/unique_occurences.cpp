/*
Given an array of integers arr, 
return true if the number of occurrences of each value in the array is unique, or false otherwise.
*/

//These solution may not be optimised, it is just for learning the concept

#include<bits/stdc++.h>

using namespace std;

bool uniqueOccurrences(int* arr, int arrSize)
{
    int i, j, arr1[arrSize], k;
    int n = arrSize, count=0;

//Initializing the arr1 with -1
    for(i=0; i<n; i++)
        arr1[i] = -1;
    
//Storing the count of each elements of arr in arr1    
for(i=0; i<n; i++)
    {
        int count = 1;
        for(j=i+1; j<n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                arr1[j] = 0;
            }
        }
        
        if(arr1[i] != 0)
           arr1[i] = count;
    }
    
//Checking for unique occurrences    
for(i=0; i<n; i++)

    {
        if(arr1[i] != 0)
        {
           for(j=i+1;  j<n;  j++)
           {
                if((arr1[i] == arr1[j]))
                    return false;
           } 
        }
        
    }
    return true;
}

int main(){
  int arr[] = {1,1,1,2,2,3,3,3,3,4};
  int n = sizeof(arr)/sizeof(int);

  bool ans = uniqueOccurrences(arr,n);

  if(ans == true) cout << "unique";
  else{
    cout << "not unique"; 
  }

  return 0;
}