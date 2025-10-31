#include "CookHeader.h"

// 이진 탐색 트리의 노드 구조체 정의
typedef struct _TreeNode {
    struct _TreeNode* left = NULL;   // 왼쪽 자식 노드에 대한 포인터
    string data;                    // 노드에 저장될 데이터 (그룹 이름)
    struct _TreeNode* right = NULL;  // 오른쪽 자식 노드에 대한 포인터
} TreeNode;

// 동적 할당된 노드들을 저장하여 메모리 관리를 위한 배열
Array <TreeNode*> memory;
// 트리의 루트 노드 포인터
TreeNode* root = NULL;
// 삽입할 그룹 이름 배열
Array <string> nameAry = { "블랙핑크", "레드벨벳", "마마무", "에이핑크", "걸스데이", "트와이스" };

// 메모리 해제 함수: 동적 할당된 모든 노드를 삭제
void freeMemory(){
    for (int i = 0; i < len(memory); i++) 
        delete memory[i];
}

int main(){
    TreeNode* node;  // 새 노드를 생성할 때 사용할 포인터
    TreeNode* current;  // 트리를 순회할 때 사용할 현재 노드 포인터

    // 루트 노드 생성 및 초기화
    node = new TreeNode();
    node->data = nameAry[0];  // 첫 번째 그룹 이름을 루트로 설정
    root = node;
    memory.push_back(node);  // 메모리 관리 배열에 추가

    // 나머지 그룹 이름들을 트리에 삽입
    for(int i = 1; i < len(nameAry); i++){
        string name = nameAry[i];  // 현재 삽입할 그룹 이름
        node = new TreeNode();     // 새 노드 생성
        node->data = name;         // 노드에 데이터 설정

        current = root;  // 루트부터 시작하여 삽입 위치 찾기

        // 이진 탐색 트리 삽입 로직: 왼쪽 또는 오른쪽으로 이동하며 빈 자리 찾기
        while(true){
            if(name < current->data){  // 삽입할 이름이 현재 노드보다 작으면 왼쪽
                if(current->left == NULL){  // 왼쪽 자식이 없으면 삽입
                    current->left = node;
                    break;
                }
                else{  // 왼쪽 자식으로 이동
                    current = current->left;
                }
            }
            else{  // 삽입할 이름이 현재 노드보다 크거나 같으면 오른쪽
                if(current->right == NULL){  // 오른쪽 자식이 없으면 삽입
                    current->right = node;
                    break;
                }
                else{  // 오른쪽 자식으로 이동
                    current = current->right;
                }
            }
        }
        memory.push_back(node);  // 메모리 관리 배열에 추가
    }
    println("이진 탐색 트리 구성 완료");  // 구성 완료 메시지 출력
    freeMemory();  // 메모리 해제
}


