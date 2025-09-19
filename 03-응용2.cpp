#include "CookHeader.h"

Array <Array<int>> px = { { 300, 20, 0 }, { 7, -4,  5 } }; // 7x^300 -4x^20 + 5x^0 

string printPoly(Array <Array<int>> p_x) { // 다항식 출력 함수
	string polyStr = "P(x) = "; // 다항식 문자열

	for (int i = 0; i < len(p_x[0]); i++) { // 항 갯수는 배열 길이 - 1, 이 의미는 최고차항의 차수
		int term = p_x[0][i];	// 항 차수에 대한 배열
		int coef = p_x[1][i];	// 계수에 대한 배열
	// 2차원 배열에서 첫 번째 행은 항 차수, 두 번째 행은 계수

		if (coef >= 0) // 계수가 0보다 크면 + 기호 추가
			polyStr += "+"; // 양수일 때만 + 기호 추가
		polyStr += to_string(coef) + "x^" + to_string(term) + " "; // 계수 다음에 x^차수 추가하고 그 다음 공백 추가
		term -= 1; // 차수 하나 감소
	}

	return polyStr;
}

int calcPoly(int xVal, Array <Array<int>> p_x) { // 다항식 계산 함수
	int retValue = 0; // 초기 반환 값을 초기화

	for (int i = 0; i < len(p_x[0]); i++) { // 항의 갯수보다 작을때까지 반복
		int term = p_x[0][i];	// 항 차수
		int coef = p_x[1][i];	// 계수
		retValue += coef * (int) pow(xVal, term); // 계수 곱하기 x값의 항 차수 제곱을 더함

	}

	return retValue; // 계산값 반환
}

int main() { // 메인함수
	string pStr = printPoly(px); // 다항식 출력 함수 호출
	println(pStr); // 다항식 출력

	int xValue; // x값 변수 선언
	input(xValue, "X값-->"); // x값 입력

	int pxValue = calcPoly(xValue, px); // 다항식 계산 함수 호출
	println(pxValue); // 다항식 계산값 출력
}