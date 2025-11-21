#include "CookHeader.h"

Array <int> testAry = {55, 88, 33, 77};

int findMinIdx(Array <int> ary){ // 작은 값을 찾는 참조 배열
    int minIdx = 0; // 초기화
    for (int i = 1; i < len(ary); i++){ // 배열 길이만큼, 1부터 시작
        if (ary[i] < ary[minIdx]){ // 배열에 있는 값이 최솟값 보다 작으면 
            minIdx = i; // 최솟값 갱신
        }
    }
    return minIdx; // 최솟값 위치 반환
}