#include "..\CookHeader.h"

typedef struct _Node { // 노드 구조체 선언
	string data; // 데이터 타입 : string
	struct _Node* link = NULL; // 다음 노드를 가르키는 포인터, 링크, NULL로 초기화
} Node; // 노드라고 선언

Array <Node*> memory; // 동적할당 된 노드의 주소를 저장하는 배열
Node* head, * current, * pre; // 노드의 두성은 헤드, 현재, 이전
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