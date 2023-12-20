#include <assert.h>
#include <stdio.h>

int and(int a,int b){
    return ~(~a|~b);
}
int main(){
    assert(and(0,1)==0);
    assert(and(1,0)==0);
    assert(and(0,0)==0);
    assert(and(1,1)==1);
}