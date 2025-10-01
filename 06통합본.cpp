#include "CookHeader.h"

int SIZE;
Array <string> stackArr;
int top = -1;

bool isStackFull(){ // 가득 찼을때
    if(top == SIZE -1){ // top 숫자가 스택사이즈 -1일때 <- 이거는 컴퓨터는 0부터 시작이기 때문에 -1을 해줘야 정의한 사이즈라고 볼 수 있음
        return true;
    }
    return false;
}

bool isStackEmpty(){ // 비었을때
    if(top == -1){ // top숫자가 -1일때
        return true; // true를 반환
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

string peek(){ // 맨 위에 데이터를 출력
    if(isStackEmpty()){ // 그런데 비어있다면
        println("스택이 비어 있습니다.");
        return "None";
    }
    return stackArr[top]; // 출력
}

int main(){
    input(SIZE, "스택의 크기 입력: ");
    for (int i = 0; i < SIZE; i++)
        stackArr.push_back("None");

    char select;
    input(select, "삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택: ");

    string data;
    while(select != 'X' && select != 'x'){ // X가 아닌 경우 수행되는 반복문
        switch(select){ // select 변수에 따른 수행
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