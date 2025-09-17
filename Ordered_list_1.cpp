#include "CookHeader.h"
// 1. 선형 리스트의 추가

int main() {
    Array<string> katok = {"다현", "정연", "쯔위", "사나", "지효"};
    katok.push_back("None"); // 마지막 선형 리스트에 빈칸을 추가
    katok[5] = "모모"; // 빈칸에 모모를 추가

    katok.push_back("None"); // 마지막 공간 만들기
    katok[6] = katok[5]; // 모모를 뒤로 밀기
    katok[5] = "None"; // 빈칸으로 정의
    katok[5] = katok[4]; // 지효를 뒤로 밀기
    katok[4] = "None"; // 빈칸으로 정의
    katok[4] = katok[3]; // 사나를 뒤로 밀기
    katok[3] = "None"; // 빈칸으로 정의
    katok[3] = "미나"; // 3번 빈인덱스에 미나 추가
    printArray(katok); // 출력

    println(katok[3]);
    println(katok[6]);

    return 0;
}