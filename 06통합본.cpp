#include "CookHeader.h"

int SIZE;
Array <string> stackArr;
int top = -1;

bool isStackFull(){
    if(top == SIZE -1){
        return true;
    }
    return false;
}

bool isStackEmpty(){
    if(top == -1){
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

string pop(){
    if(isStackEmpty()){
        println("스택이 비어 있습니다.");
        return "None";
    }
    string data = stackArr[top];
    stackArr[top] = "None";
    top--;
    return data;
}

string peek(){
    if(isStackEmpty()){
        println("스택이 비어 있습니다.");
        return "None";
    }
    return stackArr[top];
}

int main(){
    input(SIZE, "스택의 크기 입력: ");
    for (int i = 0; i < SIZE; i++)
        stackArr.push_back("None");

    char select;
    input(select, "삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택: ");

    string data;
    while(select != 'X' && select != 'x'){
        switch(select){
            case 'I': case 'i':
                input(data, "삽입할 데이터 입력: ");
                push(data);
                printArray(stackArr);
                break;
            case 'E': case 'e':
                data = pop();
                if(data != "None")
                    println("추출할 데이터--> " + data);
                printArray(stackArr);
                break;
            case 'V': case 'v':
                data = peek();
                if(data != "None")
                    println("top의 데이터 확인--> " + data);
                printArray(stackArr);
                break;
            default:
                println("잘못된 선택입니다.");
        }
        input(select, "삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택: ");
    }
    println("프로그램 종료");
}