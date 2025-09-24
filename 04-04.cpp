#include "CookHeader.h"
// 노드 삭제
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

    node2->link = node3->link;
    delete node3;

    Node* current = head;
    print(current->data);
    while (current->link != NULL) {
        current = current->link;
        print(current->data);
    }
    return 0;
}