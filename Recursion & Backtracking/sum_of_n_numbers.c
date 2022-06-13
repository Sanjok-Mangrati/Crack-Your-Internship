#include<stdio.h>

int sum(int n){         //This function is not effecient, it's time & space complexity is O(n).
    if(n==1){           //This is only used to practice the Concept of Recursion
        return 1;
    }
    return n + sum(n-1);
}

void main(){
    int n;
    scanf("%d",&n);
    int result = sum(n);
    printf("%d",result);
}
