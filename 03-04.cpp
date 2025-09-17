#include "CookHeader.h"
// 데이터 추가 함수를 선언하고 메인함수에서 호출하기
Array<string> katok;
int sel_num = -1;


void add_data(string data) // 데이터 추가 방법 정의 함수
{
    katok.push_back("None"); // 마지막 선형 리스트에 빈칸을 추가
    int kLen = len(katok); // 선형 리스트의 길이
    katok[kLen - 1] = data; // 빈칸에 data를 추가
}


void insert_data(string data, int position) // 데이터 추가 방법 정의 함수
{
    if ((position < 0) || (position > len(katok))) {
        println("데이터를 추가할 수 없습니다.");
        return;
    }
    katok.push_back("None"); // 마지막 선형 리스트에 빈칸을 추가
    int kLen = len(katok); // 선형 리스트의 길이

    for (int i = kLen - 1; i > position; i--) {
        katok[i] = katok[i - 1]; // 뒤로 밀기
        katok[i - 1] = "None"; // 빈칸으로 정의
    }
    katok[position] = data; // 빈칸에 data를 추가

}

void delete_data(int position) // 데이터 삭제 방법 정의 함수
{
    if ((position < 0) || (position > len(katok))) {
        println("데이터를 추가할 수 없습니다.");
        return;
    }
    int kLen = len(katok); // 선형 리스트의 길이
    katok[position] = "None"; // 입력된 위치에 빈칸을 추가


    for (int i = position + 1; i < kLen; i++) { // 입력된 위치에서 리스트 끝까지 반복함
        katok[i - 1] = katok[i]; // 뒷 내용을 앞으로 밀기
        katok[i] = "None"; // 뒤로 민 것을 빈칸으로 정의
    }

    del(katok, kLen - 1); // 빈칸을 삭제

}

int main() {

    string data;
    int pos;
    while (sel_num != 4) {
        input(sel_num, "1. 데이터 추가 2. 데이터 삽입 3. 데이터 삭제 4. 종료 : ");

        switch (sel_num) {
        case 1:
            input(data, "추가할 데이터: ");
            add_data(data);
            printArray(katok);
            break;
        case 2:
            input(pos, "삽입할 위치: ");
            input(data, "삽입할 데이터: ");
            insert_data(data, pos);
            printArray(katok);
            break;
        case 3:
            input(pos, "삭제할 위치: ");
            delete_data(pos);
            printArray(katok);
            break;
        case 4:
            printArray(katok);
            return 0;
        default:
            println("잘못된 입력입니다.");
            break;
        }
    }
}