#include "CookHeader.h"

Array <int> dataAry = { 50, 105, 120, 188, 150, 162, 168, 177 };

Array <int> bubbleSort(Array <int> ary){
    int n = len(ary);
    for (int end = n-1; end > 0; end--){
        bool changedYN = false;
        print("#사이클-->");
        printArray(ary);
        for (int cur = 0; cur < end; cur++){
            if (ary[cur] > ary[cur + 1]){
                int temp = ary[cur];
                ary[cur] = ary[cur + 1];
                ary[cur + 1] = temp;
                changedYN = true;
            }
        }
        if (!changedYN)
            break;
    }
    return ary;
}

int main() {
    print("정렬 전 배열: ");
    printArray(dataAry);
    Array <int> sortedAry = bubbleSort(dataAry);
    print("정렬 후 배열: ");
    printArray(sortedAry);
}