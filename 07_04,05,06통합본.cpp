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

bool isQueueEmpty(){ // 큐가 비었는지 확인
    if(front == rear){ // front와 rear가 같다면
        return true; // 비어있다
    }
    return false;
}

string deQueue(){ // 큐에서 데이터 추출
    if(isQueueEmpty()){ // 만약 비어있다면
        println("큐가 비어 있습니다."); // 출력하고
        return "None"; // None을 반환
    }
    front++; // 그게 아니라면 front를 하나 증가시키고
    string data = queueArr[front]; // 출구에 있는 데이터를 data에 저장
    queueArr[front] = "None"; // 출구에 있는 데이터를 None으로 초기화
    return data; // data 반환
}

string peek(){ // 맨 앞에 데이터를 출력
    if(isQueueEmpty()){ // 그런데 비어있다면
        println("큐가 비어 있습니다.");
        return "None"; // None 반환
    }
    return queueArr[front + 1]; // 출력
}

void enQueue(string data){ // 큐에 데이터 삽입
    if(isQueueFull()){ // 만약 찼다면 
        println("큐가 가득 찼습니다."); //출력하고
        return; // 그냥 리턴
    }
    rear++; // 그게 아니라면 rear를 하나 증가시키고
    queueArr[rear] = data; // 입구에 데이터를 삽입
}

int main(){
    printArray(queueArr);
    enQueue("선미");
    printArray(queueArr);
    enQueue("재남");
}