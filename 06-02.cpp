#include "CookHeader.h"

Array <string> stackArr = {"커피", "녹차", "꿀물", "None", "None"};
int top = 2;

int main(){
    println("현재 스택 상태");
    for(int i = top; i >= 0; i--){
        println(stackArr[i]);
    }
    // 전체 배열(빈 슬롯 포함) 출력 (디버그용)
    println("[전체 배열 상태]");
    for(int i = len(stackArr) - 1; i >= 0; --i){
        println(stackArr[i]);
    }

    string data;
    println("-------------------");
    data = stackArr[top];
    stackArr[top] = "None";
    top--;
    println("pop--> " + data);

    data = stackArr[top];
    stackArr[top] = "None";
    top--;
    println("pop--> " + data);

    data = stackArr[top];
    stackArr[top] = "None";
    top--;
    println("pop--> " + data);
    println("-------------------");

    println("현재 스택 상태");
    for(int i = top; i >= 0; i--){
        println(stackArr[i]);
    }
    // 팝 이후 전체 배열(디버그)
    println("[전체 배열 상태]");
    for(int i = len(stackArr) - 1; i >= 0; --i){
        println(stackArr[i]);
    }

}