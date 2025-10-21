#include "CookHeader.h"
//연결리스트
typedef struct _Node { //
    string data;
    struct _Node* link= NULL;
} Node;

int main(){
    Node* head;

    Node* node1 = new Node; // 새 노드 객체 생성
    node1->data = "다현"; // 1번 노드에 다현이라고 넣음
    head = node1; // 머리가 1번 노드라고 결정
 
    Node* node2 = new Node;
    node2->data = "정연";
    node1->link = node2; 

    Node* node3 = new Node;
    node3->data = "쯔위";
    node2->link = node3;

    Node* node4 = new Node;
    node4->data = "사나";
    node3->link = node4;

    Node* node5 = new Node;
    node5->data = "지효";
    node4->link = node5;

    
    print(head->data);
    print(head->link->data);
    print(head->link->link->data);
    print(head->link->link->link->data);
    print(head->link->link->link->link->data);
    
    return 0;
}