#include "CookHeader.h"

int SIZE = 5;
Array <string> stack = {"커피", "녹차", "꿀물", "콜라","환타"};
int top =4;

bool isStackFull(){
    if(top == SIZE -1){
        return true;
    }
    return false;
}
int main(){
    print("스택이 가득 찼나요? ");
    println((isStackFull()? "예" : "아니요"));
}