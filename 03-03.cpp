#include "CookHeader.h"
// 데이터 추가 함수를 선언하고 메인함수에서 호출하기
Array<string> katok = {"다현", "정연", "쯔위", "사나", "지효"};

void delete_data(int position) // 데이터 삭제 방법 정의 함수
{
    if ((position < 0) || (position > len(katok))) {
        println("데이터를 추가할 수 없습니다.");
        return;
    }
    int kLen = len(katok); // 선형 리스트의 길이
    katok[position] = "None"; // 삭제하고 싶은 위치에 빈칸으로 선언


    for (int i = position + 1; i < kLen; i++) { // 입력된 위치 다음 위치에서 리스트 끝까지 반복함
        katok[i - 1] = katok[i]; // 뒷 내용을 앞으로 밀기
        katok[i] = "None"; // 뒤로 민 것을 빈칸으로 정의
    }

    del(katok, kLen - 1); // 빈칸을 삭제

}

int main() {
    delete_data(2);
    printArray(katok);
    delete_data(4);
    printArray(katok);
}