#include <stdio.h>
#include <assert.h>

int getByte(int x,int y){
    return (x>>(y<<3)) & 0b11111111;
}
int main(){
    assert(getByte(0x12345678,1)==0x56);
    assert(getByte(0x12345678,3)==0x12);
}