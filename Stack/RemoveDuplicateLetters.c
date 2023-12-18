//QUESTION LINK
//https://leetcode.com/problems/remove-duplicate-letters/description/ 


#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

char* removeDuplicateLetters(char* s) {
    bool visit[26];
    char stack[strlen(s)];
    int top=-1;
    int freq[26];
    for(int i=0;i<26;i++){
        freq[i]=0;
        visit[i]=false;
    }
    for(int i=0;i<strlen(s);i++){
        freq[s[i]-'a']=freq[s[i]-'a']+1;
    }
    for(int i=0;i<strlen(s);i++){
        freq[s[i]-'a']=freq[s[i]-'a']-1;
        if(visit[s[i]-'a']==true) continue;
        if(top==-1){
            visit[s[i]-'a']=true;
            top+=1;
            stack[top]=s[i];
        }
        else{
            while(top!=-1 && stack[top]>s[i] && freq[stack[top]-'a']>0){
                visit[stack[top]-'a']=false;
                top-=1;
            }
            top+=1;
            stack[top]=s[i];
            visit[s[i]-'a']=true;
        }
    }
    char* ans=(char*)malloc(sizeof(char)*(top+2));
    ans[top+1]='\0';
    while(top!=-1){
        ans[top]=stack[top];
        top-=1;
    }
    return ans;
}


int main(){
    assert(strcmp(removeDuplicateLetters("bbcaac"),"bac")==0);
    assert(strcmp(removeDuplicateLetters("bcabc"),"abc")==0);
}