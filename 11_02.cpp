#include "CookHeader.h"

Array <int> before = {188, 162, 168, 120, 50, 150, 177, 105};
Array <int> after;

int findMinIdx(Array <int> ary){ // 작은 값을 찾는 참조 배열
    int minIdx = 0; // 초기화
    for (int i = 1; i < len(ary); i++){ // 배열 길이만큼, 1부터 시작
        if (ary[i] < ary[minIdx]){ // 배열에 있는 값이 최솟값 보다 작으면 
            minIdx = i; // 최솟값 갱신
        }
    }
    return minIdx; // 최솟값 위치 반환
}

int main(){ // 메인 함수 선언부
    print("정렬 전 배열: "); 
    printArray(before); // 정렬 정 배열 출력
    int arySize = len(before); // 배열 크기는 이전 배열길이
    for (int i = 0; i < arySize; i++){ // 0부터 배열 크기 만큼 반복
        int minPos = findMinIdx(before); // 최솟값을 이전 배열에서 찾기
        after.push_back(before[minPos]); //  그래서 최솟값을 before 배열에서 after 배열로 넣기
        del(before, minPos); // 이전 배열에서 최솟값 위치 삭제

    }
    print("정렬 후 배열: ");
    printArray(after);
}