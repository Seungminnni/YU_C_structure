#include "CookHeader.h"
// 데이터 추가 함수를 선언하고 메인함수에서 호출하기
Array<string> katok;

void add_data(string data) // 데이터 추가 방법 정의 함수
{
    katok.push_back("None"); // 마지막 선형 리스트에 빈칸을 추가
    int kLen = len(katok); // 선형 리스트의 길이
    katok[kLen - 1] = data; // 빈칸에 data를 추가

}

int main() {
    add_data("성혁");
    add_data("승민");
    add_data("우지");
    add_data("형규");
    add_data("정웅");
    
    printArray(katok);
}