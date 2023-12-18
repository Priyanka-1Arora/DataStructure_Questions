#include <stdio.h>
#include <string.h>
#include <assert.h>

int longestValidParentheses(char* s) {
    int arr[50000];
    int top=0;
    arr[top]=-1;
    int res=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='('){
            top+=1;
            arr[top]=i;
        }
        else{
            top-=1;
            if(top==-1){
                top+=1;
                arr[top]=i;
            }
            else{
                int val=i-arr[top];
                if(val>res) res=val;
            }
        }
    }
    return res;
}


int main(){
    assert(longestValidParentheses("())")==2);
    assert(longestValidParentheses("(())())")==6);
}