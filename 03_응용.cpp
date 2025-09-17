#include "CookHeader.h"
// 데이터 추가 함수를 선언하고 메인함수에서 호출하기
Array<Array<string>> katok = {{"성혁", "200"}, {"승민", "250"}, {"우지", "300"}, {"형규", "400"}, {"정웅", "500"}};

void insert_data(int position, Array<string> pairData) // 데이터 추가 방법 정의 함수
{
    if ((position < 0) || (position > len(katok))) {
        println("데이터를 추가할 수 없습니다.");
        return;
    }
    katok.push_back({"None", "None"}); // 마지막 선형 리스트에 빈칸을 추가
    int kLen = len(katok); // 선형 리스트의 길이

    for (int i = kLen - 1; i > position; i--) {
        katok[i] = katok[i - 1]; // 뒤로 밀기
        katok[i - 1] = {"None", "None"}; // 빈칸으로 정의
    }
    katok[position] = pairData; // 빈칸에 data를 추가

}

void find_and_insert_data(int position, Array<string> pairData) // 데이터 삽입 방법 정의 함수
{
    int findPos = -1;

    for (int i = 0; i < len(katok); i++) {
        Array<string> pair = katok[i];
        if (stoi(pair[1]) < stoi(pairData[1])) {
            findPos = i;
            break;
        }
    }
    if (findPos == -1) // 찾지 못했으면 맨 뒤에 추가
        findPos = len(katok);
    insert_data(findPos, pairData);


}

int main() {

    string data;
    int pos;

        }
    }
}