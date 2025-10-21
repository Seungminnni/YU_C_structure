#include "CookHeader.h"
//노드 삽입, 내용 추가
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

    Node* newNode = new Node; // 새로운 노드 객체 생성
    newNode->data = "재남"; // 새로운 노드의 데이터는 재남
    newNode->link = node2->link; // 새로운 노드의 링크는 노드 2로 링크를 통해 이뤄짐
    node2->link = newNode; // 노트 2에서 다음으로 이어지는 것은 새로운 노드다

    Node* current = head;
    print(current->data);
    while (current->link != NULL) {
        current = current->link;
        print(current->data);
    }
    return 0;
}