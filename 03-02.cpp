#include "CookHeader.h"
// 데이터 추가 함수를 선언하고 메인함수에서 호출하기
Array<string> katok = {"다현", "정연", "쯔위", "사나", "지효"};

void add_data(string data, int position) // 데이터 추가 방법 정의 함수
{
    if ((position < 0) || (position > len(katok))) { // 입력한 위치가 0보다 작거나 
        // 배열길이보다 크면 안된다는 예외처리
        println("데이터를 추가할 수 없습니다.");
        return;
    }
    katok.push_back("None"); // 마지막 선형 리스트에 빈칸을 추가
    int kLen = len(katok); // 선형 리스트의 길이

    for (int i = kLen - 1; i > position; i--) { // 마지막에서 부터 입력한 포지션까지 빼기해서 위치 도달 할때까지 반복
        katok[i] = katok[i - 1]; // 한칸씩 뒤로 밀기 
        katok[i - 1] = "None"; // 밀어낸 칸을 빈칸으로 정의
    }
    katok[position] = data; // 빈칸에 data를 추가

}

int main() {
    add_data("성혁", 2);
    printArray(katok);
    add_data("승민", 6);
    printArray(katok);
}