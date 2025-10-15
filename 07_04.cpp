#include "CookHeader.h"

int SIZE = 5;
Array <string> queueArr = {"화사", "솔라", "문별", "휘인", "None"}; // 큐 알고리즘 정의
int front = -1, rear = 3; // 입구와 출구를 정의

bool isQueueFull(){ // 큐가 가득 찼는지 확인
    if(rear == SIZE -1){ 
        return true;
    }
    return false;
}

void enQueue(string data){
    if(isQueueFull()){
        println("큐가 가득 찼습니다.");
        return;
    }
    rear++;
    queueArr[rear] = data;
}

int main(){
    printArray(queueArr);
    enQueue("선미");
    printArray(queueArr);
    enQueue("재남");
}