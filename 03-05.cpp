#include "CookHeader.h"

Array <int> px = {-7, -4, 0, 5};

// 입력: 계수 배열 p_x 출력: "P(x) = +계수x^차수 + ..." 형태의 문자열
string print_poly(Array <int> p_x){ // 다항식 출력 함수
    // 최고차항의 차수를 계산 (배열 길이 - 1) 길이 4이면 최고차항은 x^3
    int term = len(p_x) -1; // 항 갯수는 배열 길이 - 1, 이 의미는 최고차항의 차수

    // 결과 문자열 초기화
    string polyStr = "P(x) = "; //

    // 각 계수에 대해 반복
    for (int i = 0; i < len(p_x); i++){ // 계수의 수 만큼 반복
        int coef = p_x[i]; // 현재 계수를 coef에 저장

        // 계수가 양수이면 '+' 부호 추가 (음수는 이미 '-' 포함)
        if (coef >= 0) // 계수가 1보다 작거나 같을때 
            polyStr += "+";

        // 계수, x, ^, 차수를 문자열로 추가
        polyStr += to_string(coef) + "x^" + to_string(term); // 다항식 += 계수 + x^+차수

        
        term--; // 다음 항의 차수 감소
    }
    return polyStr; // 완성된 다항식 문자열 반환
}

// 주어진 x 값에 대해 다항식의 값을 계산하는 함수
// 입력: x 값 (xVal), 계수 배열 (p_x)
// 출력: 계산된 다항식 값 (int)
int calcPoly(int xVal, Array <int> p_x){ // 다항식 계산 함수
    int retValue = 0; // 결과를 저장할 변수, 초기값 0
    int term = len(p_x)-1; // 최고차항의 차수 만약 4개의 계수가 있으면 x^3이런식  

    for (int i = 0; i < len(p_x); i++){ // 개수의 갯수만큼 반복
        int coef = p_x[i]; // 현재 계수

        retValue += coef * pow(xVal, term); // 계산결과는 계수 곱하기 x의 차수 제곱

        // 다음 항의 차수 감소
        term--;
    }

    // 계산된 값 반환
    return retValue;
}

int main() {
    // 다항식을 문자열로 변환하여 출력
    string pStr = print_poly(px);
    println(pStr);

    // 사용자로부터 x 값을 입력받음
    int xValue;
    input(xValue, "x 값 입력: ");

    // 입력된 x 값으로 다항식 계산
    int pxValue = calcPoly(xValue, px);

    // 계산된 값 출력
    println(pxValue);
}