#include "CookHeader.h"

typedef struct _Node {
    string data;
    struct _Node* link= NULL;
} Node;

Array <Node*> memory;
Node * head, * current,* pre;
Array<string> dataArray = {"다현", "정연", "쯔위", "사나", "지효"};

void printNodes(Node* start){ // 노드 출력 함수 시작
    if(start == NULL) // 시작 노드가 NULL이면
    return; // 함수 종료

    Node* current = start; // 현재 노드는 출발
    print(current->data); // 현제 데이터 출력
    while (current->link != NULL) { // 링크가 NULL이 아닐때까지 반복
        current = current->link; // 다음 노드로 이동
        print(current->data); // 다음 노드의 데이터 출력
    }
    println("");
}

void freeMemory(){
    for(int i = 0; i < len(memory); i++){
        delete memory[i];
    }
}

int main() {
    Node* node = new Node; // 새 노드 객체 생성
    node->data = dataArray[0]; // 1번 노드에 데이터 넣음
    head = node; // 머리가 1번 노드라고 결정
    memory.push_back(node); // 메모리에 할당

    for (int i = 1; i < len(dataArray); i++){ // 데이터 배열 길이만큼 반복
        string data = dataArray[i]; // 데이터 배열에서 데이터 추출
        pre = node; // 이전 노드는 노드
        node = new Node; // 새 노드 객체 생성
        node->data = data; // 노드에 데이터 넣음
        pre->link = node; // 이전 노드의 링크는 현재 노드
        memory.push_back(node); // 메모리에 할당
    }
    printNodes(head); // 노드 출력 함수 호출
    freeMemory(); // 메모리 해제
    return 0;
}
