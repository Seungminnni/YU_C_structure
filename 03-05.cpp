#include "CookHeader.h"

Array <int> px = {-7, -4, 0, 5};

string print_poly(Array <int> p_x){
    int term = len(p_x);
    string polyStr = "P(x) = ";

    for (int i = 0; i < len(p_x); i++){
        int coef = p_x[i];

        if (coef >= 0) 
            polyStr += "+";
        polyStr += to_string(coef) + "x^" + to_string(term);
        term--;
}

    return polyStr;
}

int calcPoly(int xVal, Array <int> p_x){
    int retValue = 0;
    int term = len(p_x)-1;

    for (int i = 0; i < len(p_x); i++){
        int coef = p_x[i];
        retValue += coef * pow(xVal, term);
        term--;
    }

    return retValue;
}

int main() {
    string pStr = print_poly(px);
    println(pStr);

    int xValue;
    input(xValue, "x 값 입력: ");

    int pxValue = calcPoly(xValue, px);
    println(pxValue);
}