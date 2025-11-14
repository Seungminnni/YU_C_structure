#include "CookHeader.h"

int factorial(int num){ // 재귀함수로 팩토리얼 계산
    int retValue; // 반환값 변수
    if (num <= 1){
        println("1반환");
        return 1; // 종료조건: num이 1 이하일 때 1 반환
    }
    println(to_string(num) + " * factorial(" + to_string(num - 1) + ") 호출");
    retValue = factorial(num - 1); // 재귀 호출: num

    println(to_string(num) + " * " + to_string(num - 1) + "!(=" + to_string(retValue) + ") 반환");
    return num * retValue; // num 곱하기 factorial(num-1) 반환
}

int main(){
    println("\n5! = " + to_string(factorial(5)) ); // 5! 계산 및 출력
}
