#include "CookHeader.h"

typedef struct _DoubleNode { // 노드 구조체 선언
	struct _DoubleNode* pLink = NULL; // 이전 노드를 가르키는 포인터, NULL로 초기화
    string data; // 데이터 타입 : string
	struct _DoubleNode* nLink = NULL; // 다음 노드를 가르키는 포인터, NULL로 초기화
} DoubleNode; // 노드라고 선언

Array <DoubleNode*> memory; // 동적할당 된 노드의 주소를 저장하는 배열
DoubleNode* head, * current, * pre; // 노드의 두성은 헤드, 현재, 이전
Array <string> dataArray = { "다현", "정연", "채영", "쯔위", "사나" };

void printDoubleNodes(DoubleNode* start) {
    DoubleNode* current = start;
    if(current->nLink==NULL)
        return;
    print("정방향: ");
    print(current->data);
    while (current->nLink != NULL) {
        current = current->nLink;
        print(current->data);
    }
    println("");
    print("역방향: ");
    print(current->data);
    while (current->pLink != NULL) {
        current = current->pLink;
        print(current->data);
    }
    println("");
}

void freeMemory() { // 메모리 해제 함수
    for (int i = 0; i < len(memory); i++)
        delete memory[i];
}

int main() {
    DoubleNode* node = new DoubleNode; // 노드 동적할당
    node->data = dataArray[0]; // 데이터 넣기
    head = node; // 헤드가 첫 노드를 가르킴
    memory.push_back(node); // 메모리 해제용 배열에 주소 저장

    for (int i = 1; i < len(dataArray); i++) {
        string data = dataArray[i];
        pre = node; // 이전 노드
        node = new DoubleNode; // 노드 동적할당
        node->data = data; // 데이터 넣기
        pre->nLink = node; // 이전 노드의 다음 노드를 현재 노드
        node->pLink = pre; // 현재 노드의 이전 노드를 이전 노드
        memory.push_back(node); // 메모리 해제용 배열에 주소 저장
        
    }
    printDoubleNodes(head);

    freeMemory(); // 메모리 해제
}

