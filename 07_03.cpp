#include "CookHeader.h"

int SIZE = 5;
Array <string> queueArr = {"화사", "솔라", "문별", "휘인", "선미"};
int front = -1, rear = 4;

bool isQueueFull(){
    if(rear == SIZE -1){
        return true;
    }
    return false;
}

int main(){
    print("큐가 꽉 찼는지?): ");
    println((isQueueFull() ? "예" : "아니오"));
}