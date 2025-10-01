#include "CookHeader.h"

int SIZE = 5;
Array <string> stackArr = {"커피", "녹차", "꿀물", "콜라","None"};
int top =3;

bool isStackFull(){
    if(top == SIZE -1){
        return true;
    }
    return false;
}

void push(string data){
    if(isStackFull()){
        println("스택이 가득 찼습니다.");
        return;
    }
    top++;
    stackArr[top] = data;
}

int main(){
    printArray(stackArr);
    push("환타");
    printArray(stackArr);
    push("사이다");
}