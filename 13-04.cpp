#include "CookHeader.h"

Array <Array <string>> bookAry = { {"어린왕자", "쌩떽쥐베리"}, {"이방인", "까뮈"},
	{"부활", "톨스토이"}, {"신곡", "단테"}, {"돈키호테", "세르반테스"}, 
	{"동물농장", "조지오웰"}, {"데미안", "헤르만헤세"}, {"파우스트", "괴테"}, {"대지", "펄벅"} };
Array <Array <string>> nameIndex, authIndex;

Array <Array <string>> makeIndex(Array <Array <string>> ary, int pos) { // 인덱스 생성함수
	Array <Array <string>> sortedAry; // 정렬된 인덱스 배열
	int index = 0; // 인덱스 값 초기화
	for (int i = 0; i < len(ary); i++) { //i증가를 배열의 길이만큼 반복
		Array <string> data = ary[i]; // 도서 배열에서 i번째 도서 데이터 가져오기
		sortedAry.push_back({ data[pos] , to_string(index) }); // 정렬된 배열에 {도서명 or 작가명, 인덱스} 추가
		index++; // 인덱스 값 1 증가
	}
	sortArray(sortedAry); // 앞 데이터로 정렬.
	return sortedAry; // 정렬된 인덱스 배열 반환
}

int bookSearch(Array <Array <string>> ary, string fData) { // 도서 검색 함수
	int pos = -1; // 찾지 못했을 때 반환할 값
	int start = 0; // 이진 탐색 시작 인덱스
	int end = len(ary) - 1; // 이진 탐색 끝 인덱스

	while (start <= end) { // 시작 인덱스가 끝 인덱스보다 작거나 같을 때 반복
		int mid = (start + end) / 2; // 중간 인덱스 계산
		if (fData == ary[mid][0]) // 찾는 데이터가 중간 데이터와 같으면
			return stoi(ary[mid][1]); // 인덱스 반환
		else if (fData > ary[mid][0]) // 찾는 데이터가 중간 데이터보다 크면
			start = mid + 1; // 시작 인덱스를 중간 인덱스 + 1로 설정
		else // 찾는 데이터가 중간 데이터보다 작으면
			end = mid - 1; // 끝 인덱스를 중간 인덱스 - 1로 설정
	}
	return pos;
}

int main() {
	print("# 책장의 도서 ==>");
	printArray2(bookAry);
	println("");

	nameIndex = makeIndex(bookAry, 0);
	print("# 도서명 색인표 ==>");
	printArray2(nameIndex);
	println("");

	authIndex = makeIndex(bookAry, 1);
	print("# 작가명 색인표 ==>");
	printArray2(authIndex);
	println("");

	string findName = "신곡";
	int findPos = bookSearch(nameIndex, findName);
	if (findPos != -1) {
		println(findName + "의 작가는 " + bookAry[findPos][1] + "입니다.");
	}
	else {
		println(findName + " 책은 없습니다.");
	}

	findName = "괴테";
	findPos = bookSearch(authIndex, findName);
	if (findPos != -1) {
		println(findName + "의 도서는 " + bookAry[findPos][0] + "입니다.");
	}
	else {
		println(findName + " 작가는 없습니다.");
	}
}