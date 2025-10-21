#include "CookHeader.h"

int main() {
    Array <Array <int>> totalLotto; // 최종 로또 번호를 담는 2차원 배열 선언
    Array <int> lotto; // 한번 생성할때 담아 둘 배열 선언
    int pickNum; // 뽑힌 번호를 선언
    int totCount; // 횟수 선언

    println("** 로또 번호 생성을 시작합니다. **");
    input(totCount, "몇 번을 뽑을까요? ");

    randomInit(1, 45); //1~45 사이의 난수를 뽑도록 초기화
    for (int i = 0; i < totCount; i++) { // 0에서 최종 횟수까지 반복
        lotto = {}; // 처음엔 빈것으로 초기화
        while (true) { // 계속 반복
            pickNum = cookRandom(gen); // 뽑힌 번호는 랜덤으로 생성됨
            if (!(isInArray(lotto, pickNum))) // 만약 뽑힌 번호가 배열에 있지 않다면
                lotto.push_back(pickNum); // 뽑힌 번호를 배열에 추가
            if (len(lotto) >= 6) // 로또 번호가 6개 이상이 된다면 
                break; //반복문 종료
        }
        totalLotto.push_back(lotto); // 로또 배열에 있는 내용을 최종 로또 배열에 추가
    }

    for (int i = 0; i < totCount; i++) { // i기 0에서 최종 횟수까지 반복
        lotto = totalLotto[i]; // 로또 배열에 있는 내용이 최종 로또 배열에 들어감
        sortArray(lotto); // 로또 배열을 정리
        print("자동번호--> "); // 자동번호 출력
        printArray(lotto); // 로또 배열 출력
    }
}