// QUESTION LINK
// https://leetcode.com/problems/valid-parentheses/description/ 


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

bool validParenthesis(char* s){
    char arr[strlen(s)];
    int top=-1;
    for(int i=0;i<strlen(s);i++){
        if((s[i]==')' && top==-1) || (s[i]==')' && arr[top]!='(')){
            return false;
        }
        if((s[i]==']' && top==-1) || (s[i]==']' && arr[top]!='[')){
            return false;
        }
        if((s[i]=='}' && top==-1) || (s[i]=='}' && arr[top]!='{')){
            return false;
        }
        if(s[i]==')' && arr[top]=='('){
            top-=1;
        }
        if(s[i]==']' && arr[top]=='['){
            top-=1;
        }
        if(s[i]=='}' && arr[top]=='{'){
            top-=1;
        }
        if(s[i]=='[' || s[i]=='{' || s[i]=='('){
            top+=1;
            arr[top]=s[i];
        }
    }
    return top==-1?true:false;
}
int main(){
    assert(validParenthesis("([{}])")==true);
    assert(validParenthesis("({])")==false);
    assert(validParenthesis("([{}]){")==false);
}