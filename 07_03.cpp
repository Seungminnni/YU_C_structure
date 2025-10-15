#include "CookHeader.h"

int SIZE = 5;
Array <string> queueArr = {"화사", "솔라", "문별", "휘인", "선미"}; // 큐 알고리즘 정의
int front = -1, rear = 4; // 입구와 출구를 정의

bool isQueueFull(){ // 큐가 가득 찼는지 확인
    if(rear == SIZE -1){ 
        return true;
    }
    return false;
}

int main(){
    print("큐가 꽉 찼는지?): ");
    println((isQueueFull() ? "예" : "아니오"));
}