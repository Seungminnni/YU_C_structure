#include "CookHeader.h"

typedef struct _Node {
    string data;
    struct _Node* link= NULL;
} Node;

Array <Node*> memory;
Node * head, * current,* pre;
Array<string> dataArray = {"다현", "정연", "쯔위", "사나", "지효"};

void printNodes(Node* start){
    if(start == NULL) 
    return;

    Node* current = start;
    print(current->data);
    while (current->link != NULL) {
        current = current->link;
        print(current->data);
    }
    println("");
}

void freeMemory(){
    for(int i = 0; i < len(memory); i++){
        delete memory[i];
    }
}

void insertNode(string findData, string insertData){
    Node* node;
    if(head->data == findData){
        node = new Node;
        node->data = insertData;
        node->link = head;
        head = node;
        memory.push_back(node);
        return;
    }
    current = head;
    while(current->link != NULL){
        pre = current;
        current = current->link;
        if(current->data == findData){
            node = new Node;
            node->data = insertData;
            pre->link = node;
            node->link = current;
            memory.push_back(node);
            return;
        }
    }
    node = new Node;
    node->data = insertData;
    current->link = node;
    memory.push_back(node);
}

int main() {
    Node* node = new Node;
    node->data = dataArray[0];
    head = node;
    memory.push_back(node);

    for (int i = 1; i < len(dataArray); i++){
        string data = dataArray[i];
        pre = node;
        node = new Node;
        node->data = data;
        pre->link = node;
        memory.push_back(node);
    }
    insertNode("다현", "화사");
    printNodes(head);
    insertNode("사나", "솔라");
    printNodes(head);
    insertNode("재남", "문별");
    printNodes(head);
    
    freeMemory();

    return 0;
}
