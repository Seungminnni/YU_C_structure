#include "CookHeader.h"

Array <string> stackArr = {"None", "None", "None", "None", "None"};
int top = -1;

int main(){
    top++;
    stackArr[top] = "커피";
    top++;
    stackArr[top] = "녹차";
    top++;
    stackArr[top] = "꿀물";

    println("현재 스택 상태");
    for(int i = top; i > -1; i--){
        println(stackArr[i]);
    }





}