#include<stdio.h>
#include<string.h>

int reverse(char str[],int i,int len){
    if(i==len/2)
        return 1;
    if(str[i]!=str[len - i - 1])
        return 0;

    return reverse(str,i+1,len);
}

void main(){
    char str[50];
    scanf("%s",str);
    
    int len = 0;
    while(str[len] != '\0'){       //Finding actual length of string
        len++;
    }

    if(!reverse(str,0,len))
        printf("Not Palindrome");
    else printf("Palindrome");
}

/*
In cpp

#include<iostream>

using namespace std;

bool reverse(int i, string str){
    if(i==str.size()/2)
        return true;
    if(str[i] != str[str.size() - i - 1])
        return false;
    return reverse(i+1,str);
}

int main(){
    string str;
    cin >> str;
    bool check = reverse(0,str);
    if(check)
        cout << "Palindrome";
    else cout << "Not Palindrome";
    return 0;
}

*/

