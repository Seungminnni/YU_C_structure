#include "CookHeader.h"

void countDown(int n){
    if (n ==0){
        println("발사!");
        return;
    }
    else{
        println(n);
        countDown(n -1);
    }
}
int main(){
    countDown(5);
}