#include "CookHeader.h"

Array <int> testAry = {55, 88, 33, 77};

int findMinIdx(Array <int> ary){
    int minIdx = 0;
    for (int i = 1; i < len(ary); i++){
        if (ary[i] < ary[minIdx]){
            minIdx = i;
        }
    }
    return minIdx;
}