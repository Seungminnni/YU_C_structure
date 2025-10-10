# include "CookHeader.h"

int SIZE;
Array <string> stackArr;
int top = -1;

bool isStackFull(){ // 가득 찼을때
    if(top == SIZE -1){ // top 숫자가 사이즈 -1일때 
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


int main(){
    SIZE = 10; // 스택 사이즈가 10으로 지정
    for (int i = 0; i < SIZE; i++) //  반복문 i가 0부터 SIZE까지
        stackArr.push_back("None"); // None으로 값을 초기화

    Array <string> colorAry = {"빨강", "파랑", "초록", "노랑", "보라", "주황"}; // 색깔 배열을 정의
    randomInit(1, len(colorAry) -1); // 1부터 색깔배열의 끝까지 랜덤으로 초기화
    for (int i = 0; i < len(colorAry) * 100; i++){ // 
        int n1 = cookRandom(gen);
        int n2 = cookRandom(gen);
        swap(colorAry[n1], colorAry[n2]);
    }
    print("과자집에 가는 길 : ");
    for (int i = 0; i < len(colorAry); i++){
        string color = colorAry[i];
        print(color + "-->");
    }
    println("과자집 도착");

    print("우리집에 오는 길 : ");
    while(true){
        string color = pop();
        if(color == "None")
            break;
        print(color + "-->");
    }
    println("우리집 도착");
}