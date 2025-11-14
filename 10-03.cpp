#include "CookHeader.h"

int addNumber(int num){ // 재귀함수로 1부터 num까지 더하는 함수
    if(num == 1) // 종료조건: num이 1일 때
        return 1; // 1 반환
    else
        return num + addNumber(num - 1); // 재귀 호출: num 더하기 addNumber(num-1)
}

int main(){
    print(addNumber(10)); // 1부터 10까지 더한 결과 출력
}

