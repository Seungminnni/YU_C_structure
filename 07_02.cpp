#include "CookHeader.h"

Array <string> queueArr = {"화사", "솔라", "문별", "None", "None"};
int front = -1, rear = 2;

int main(){
    println("큐 상태");
    print("[출구]<--");
    for(int i = 0; i < len(queueArr); i++)
        print(queueArr[i] + "<--");
    
    println("[입구]");

    string data;

    front++;
    data = queueArr[front];
    queueArr[front] = "None";
    println("dequeue --> " + data);

    front++;
    data = queueArr[front];
    queueArr[front] = "None";
    println("dequeue --> " + data);

    front++;
    data = queueArr[front];
    queueArr[front] = "None";
    println("dequeue --> " + data);

    println("큐 상태");
    print("[출구]<--");
    for(int i = 0; i < len(queueArr); i++){
        print(queueArr[i] + "<--");
    }
    println("[입구]");

}
