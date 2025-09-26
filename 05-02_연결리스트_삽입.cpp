#include "CookHeader.h"

typedef struct _Node {
	string data;
	struct _Node* link = NULL;
} Node;

int main() {
	Node* head;

	Node* node1 = new Node;
	node1->data = "다현";
	head = node1;
	node1->link = head;
		
	Node* node2 = new Node;
	node2->data = "정연";
	node1->link = node2;
	node2->link = head;
	
	Node* node3 = new Node;
	node3->data = "채영";
	node2->link = node3;
	node3->link = head;
	
	Node* node4 = new Node;
	node4->data = "쯔위";
	node3->link = node4;
	node4->link = head;
	
	Node* node5 = new Node;
	node5->data = "사나";
	node4->link = node5;
	node5->link = head;

	Node* newNode = new Node;
	newNode->data = "재남";
	newNode->link = node2->link;
	node2->link = newNode;

	Node* current = head;
	print(current->data);
	while (current->link != head) {
		current = current->link;
		print(current->data);
	}
}