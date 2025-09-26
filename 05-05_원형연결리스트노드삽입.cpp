#include "..\CookHeader.h"

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

void freeMemory() { // 메모리 해제 함수
	for (int i = 0; i < len(memory); i++)
		delete memory[i];
}

void insertNode(string findData, string insertData) {
	Node* node;
	Node* last;
	if (head->data == findData) {	// 첫 번째 노드에 삽입
		node = new Node;
		node->data = insertData;
		node->link = head;
		last = head;				// 마지막 노드 찾기
		while (last->link != head)  // 마지막 노드 찾기
			last = last->link;		// last가 마지막 노드가 될 때까지
		last->link = node;			// 마지막 노드의 다음을 새 노드로 연결
		head = node;
		memory.push_back(node);
		return;
	}
	current = head;
	while (current->link != head) {
		pre = current;
		current = current->link;
		if (current->data == findData) {
			node = new Node;
			node->data = insertData;
			node->link = current;
			pre->link = node;
			memory.push_back(node);
			return;
		}
	}
	node = new Node;
	node->data = insertData;
	current->link = node;
	node->link = head;
	memory.push_back(node);
}

int main() {
	Node* node = new Node;
	node->data = dataArray[0]; // 첫 번째 노드 생성
	head = node;
	node->link = head;
	memory.push_back(node);

	for (int i = 1; i < len(dataArray); i++) {  // 나머지 노드 생성
		string data = dataArray[i];
		pre = node;
		node = new Node;
		node->data = data;
		pre->link = node;
		node->link = head;
		memory.push_back(node);
	}
	printNodes(head);

	insertNode("다연", "화사");
	printNodes(head);

	insertNode("사나", "솔라");
	printNodes(head);

	insertNode("재남", "문별");
	printNodes(head);

	freeMemory();
}