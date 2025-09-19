#include "CookHeader.h"

Array <int> tx = { 300, 20, 0 };
Array <int> px = { 7, -4,  5 };

string printPoly(Array <int> t_x, Array <int> p_x) {
	string polyStr = "P(x) = ";

	for (int i = 0; i < len(p_x); i++) {
		int term = t_x[i];	// 항 갯수
		int coef = p_x[i];	// 계수

		if (coef >= 0)
			polyStr += "+";
		polyStr += to_string(coef) + "x^" + to_string(term) + " ";
		term--;
	}

	return polyStr;
}

int calcPoly(int xVal, Array <int> t_x, Array <int> p_x) {
	int retValue = 0;

	for (int i = 0; i < len(p_x); i++) {
		int term = t_x[i];	// 항 갯수
		int coef = p_x[i];	// 계수
		retValue += coef * (int)pow(xVal, term);
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