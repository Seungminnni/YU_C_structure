#include "CookHeader.h"

int SIZE;
Array <string> queueArr;
int front = 0 , rear = 0; // 입구와 출구를 정의

bool isQueueFull(){ // 큐가 가득 찼는지 확인
    if((rear + 1) % SIZE == front){
        return true;
    }
    return false;
}

bool isQueueEmpty(){ // 큐가 비었는지 확인
    if(front == rear){
        return true;
    }
    return false;
}

void enQueue(string data){ // 데이터 삽입
    if(isQueueFull()){
        println("큐가 가득 찼습니다.");
        return;
    }
    rear = (rear + 1) % SIZE;
    queueArr[rear] = data;
}

string deQueue(){ // 데이터 추출
    if(isQueueEmpty()){
        return "큐가 비었습니다.";
    }
    front = (front + 1) % SIZE;
    string data = queueArr[front];
    queueArr[front] = "None";
    return data;
}

string peek(){ // 맨 앞 데이터 확인
    if(isQueueEmpty()){
        println("큐가 비었습니다.");
        return "None";
    }
    return queueArr[(front + 1) % SIZE];
}

int main(){
    input("큐의 크기 입력: ", SIZE);
    for (int i = 0; i < SIZE; i++)
        queueArr.push_back("None");

        char select;
        string data;
    while(select != 'X' && select != 'x'){ // X가 아닌 경우 수행되는 반복문
        switch(select){ // select 변수에 따른 수행
            case 'I': case 'i':
                input(data, "삽입할 데이터 입력: ");
                enQueue(data);
                print("현재 큐 상태: ");
                printArray(queueArr);
                break;
            case 'E': case 'e':
                data = deQueue();
                if(data != "None")
                    println("deQueue --> " + data);
                    printArray(queueArr);
                    println("front: " + to_string(front) + ", rear: " + to_string(rear));
                    break;
            case 'V': case 'v':
                data = peek();
                println("다음에 나올 데이터 확인"+ data);
                printArray(queueArr);
                break;
            default:
                println("잘못된 입력입니다.");

        }
        input(select, "삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택: ");
    }
}