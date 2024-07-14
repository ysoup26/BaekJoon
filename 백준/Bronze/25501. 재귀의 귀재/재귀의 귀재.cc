#include <stdio.h>
#include <string.h>
#include <iostream>
int check; 
int recursion(const char *s, int l, int r){
    check++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char str[1000];
        scanf("%s",str);
        check = 0;
        printf("%d ", isPalindrome(str));
        printf("%d\n",check);
    }
}