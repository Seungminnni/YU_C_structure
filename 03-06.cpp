#include "CookHeader.h"

// 계수와 차수 배열을 따로 선언
Array <int> tx = { 300, 20, 0 };
Array <int> px = { 7, -4,  5 };

string printPoly(Array <int> t_x, Array <int> p_x) {
	string polyStr = "P(x) = ";

	for (int i = 0; i < len(p_x); i++) { // 계수의 수 만큼 반복
		int term = t_x[i];	// 차수 배열은 term값
		int coef = p_x[i];	// 계수 배열은 coef값

		if (coef >= 0) // 계수가 양수일 경우 
			polyStr += "+"; // + 부호 추가
		polyStr += to_string(coef) + "x^" + to_string(term) + " "; // 다항식 += 계수 + x^+차수
		term--; // 다음 항의 차수 감소
	}

	return polyStr;
}

int calcPoly(int xVal, Array <int> t_x, Array <int> p_x) { // 다항식 계산 함수
	int retValue = 0; // 결과를 저장할 변수, 초기값 0

	for (int i = 0; i < len(p_x); i++) { // 계수의 갯수만큼 반복
		int term = t_x[i];	// 차수 배열은 term값
		int coef = p_x[i];	// 계수 배역은 coef값
		retValue += coef * pow(xVal, term); 
	}

	return retValue;
}

int main() {
	string pStr = printPoly(tx, px);
	println(pStr);

	int xValue;
	input(xValue, "X-->");

	int pxValue = calcPoly(xValue, tx, px);
	println(pxValue);
}