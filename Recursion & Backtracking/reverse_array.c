#include<stdio.h>

void reverse(int arr[],int i,int n){        //Time complexity = O(n)
    if(i==n/2){
        return;
    }
    int temp = arr[i];
    arr[i] = arr[n-i-1];
    arr[n-i-1] = temp;

    reverse(arr,i+1,n);
}

void main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);
    reverse(arr,0,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}