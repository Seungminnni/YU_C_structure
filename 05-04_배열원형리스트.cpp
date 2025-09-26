#include "CookHeader.h"

typedef struct _Node {
	string data;
	struct _Node* link = NULL;
} Node;

Array <Node*> memory;
Node* head, * current, * pre;
Array <string> dataArray = { "다현", "정연", "채영", "쯔위", "사나" };

void printNodes(Node* start) {
	if (start == NULL)
		return;
	Node* current = start;
	print(current->data);
	while (current->link != start) {
		current = current->link;
		print(current->data);
	}
	println("");
}

void freeMemory() {	// 메모리 해제 함수
	for (int i = 0; i < len(memory); i++)
		delete memory[i];
}

int main() {
	Node* node = new Node;
	node->data = dataArray[0];					// 첫 번째 노드 생성
	head = node;
	node->link = head;
	memory.push_back(node);

	for (int i = 1; i < len(dataArray); i++) {	// 나머지 노드 생성
		string data = dataArray[i];
		pre = node;
		node = new Node;
		node->data = data;
		pre->link = node;
		node->link = head;
		memory.push_back(node);
	}
	printNodes(head);
	freeMemory();
}