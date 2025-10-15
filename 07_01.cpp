#include "CookHeader.h"

Array <string> queueArr = {"None", "None", "None", "None", "None"};
int front = -1, rear = -1;

int main(){
    rear++;
    queueArr[rear] = "화사";
    rear++;
    queueArr[rear] = "솔라";
    rear++;
    queueArr[rear] = "문별";

    println("현재 큐 상태");
    print("[출구]<--");
    for(int i = 0; i <= rear; i++)
        print(queueArr[i] + "<--");
    
    println("[입구]");
}
