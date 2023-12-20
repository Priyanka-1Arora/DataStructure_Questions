#include <stdio.h>
#include <assert.h>
int xor(int a,int b){
    return (~(a&b)&~(~a&~b));
}
int main(){
    assert(xor(0,0)==0);
    assert(xor(0,1)==1);
    assert(xor(1,0)==1);
    assert(xor(1,1)==0);
}