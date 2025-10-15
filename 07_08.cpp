#include "CookHeader.h"

int SIZE;
Array <string> queueArr;
int front = -1, rear = -1; // 입구와 출구를 정의

bool isQueueFull(){ // 큐가 가득 찼는지 확인
    if(rear == SIZE -1){  // 큐의 끝에 도달했는지 확인
        return true; // 가득 찼다
    }
    return false; // 가득 차지 않았다
}

bool isQueueEmpty(){ // 큐가 비었는지 확인
    if(front == rear){ // front와 rear가 같다면
        return true; // 비어있다
    }
    return false; // 비어있지 않다
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

void enQueue(string data){ // 큐에 데이터 삽입
    if(isQueueFull()){ // 만약 찼다면 
        println("큐가 가득 찼습니다."); //출력하고
        return; // 그냥 리턴
    }
    rear++; // 그게 아니라면 rear를 하나 증가시키고
    queueArr[rear] = data; // 입구에 데이터를 삽입
}

string peek(){ // 맨 앞에 데이터를 출력
    if(isQueueEmpty()){ // 그런데 비어있다면
        println("큐가 비어 있습니다.");
        return "None"; // None 반환
    }
    return queueArr[front + 1]; // 출력
}

int main(){
    input(SIZE, "큐의 크기 입력: "); 
    for (int i = 0; i < SIZE; i++) //SIZE까지 반복
        queueArr.push_back("None"); // None으로 초기화

    char select;
    input(select, "삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택: ");

    string data;
    while(select != 'X' && select != 'x'){ // X가 아닌 경우 수행되는 반복문
        switch(select){ // select 변수에 따른 수행
            case 'I': case 'i':
                input(data, "삽입할 데이터 입력: ");
                enQueue(data);
                break;
            case 'E': case 'e':
                data = deQueue();
                if(data != "None")
                    println("deQueue --> " + data);
                break;
            case 'V': case 'v':
                data = peek();
                if(data != "None")
                    println("peek --> " + data);
                break;
            default:
                println("잘못된 입력입니다.");
        }
        input(select, "삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택: ");
    }

    println("[최종 큐 상태]");
    print("[출구]<--");
    for(int i = 0; i <= rear; i++)
        print(queueArr[i] + "<--");
    
    println("[입구]");
}