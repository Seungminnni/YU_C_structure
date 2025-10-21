#include "CookHeader.h"
//연결리스트 출력 방식 개선
typedef struct _Node {
    string data;
    struct _Node* link= NULL;
} Node;

int main(){
    Node* head;

    Node* node1 = new Node;
    node1->data = "다현";
    head = node1;

    Node* node2 = new Node;
    node2->data = "정연";
    node1->link = node2; // link after node2 is created

    Node* node3 = new Node;
    node3->data = "쯔위";
    node2->link = node3;

    Node* node4 = new Node;
    node4->data = "사나";
    node3->link = node4;

    Node* node5 = new Node;
    node5->data = "지효";
    node4->link = node5;

    Node* current = head; // 현재 노드의 포인터가 머리로 시작
    print(current->data); // 현재 데이터를 출력
    while (current->link != NULL) { // 값이 있다면
        current = current->link; // 다음 노드로 이동
        print(current->data); // 다음 노드의 데이터를 출력
}
    
    return 0;
}