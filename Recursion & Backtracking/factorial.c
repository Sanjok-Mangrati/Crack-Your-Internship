#include<stdio.h>

int factorial(int n){       //This function is not effecient, it's time & space complexity is O(n).
    if(n==1){               //This is only used to practice the Concept of Recursion
        return 1;
    }
    return n * factorial(n-1);
}

void main(){
    int n;
    scanf("%d",&n);
    printf("%d",factorial(n));
}