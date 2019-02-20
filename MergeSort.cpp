#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> src) {
	for (int i = 0; i < src.size(); i++) {
		cout << src[i] << " ";
	}
	cout << "\n" << endl;
	return;
}
 

void merge(vector<int> &src, int start, int middle, int end) {
	vector<int> sorted(end+1);
	int i = start; // 왼쪽 시작
	int j = middle + 1; // 오른쪽 시작
	int s = start; //sorted 함수 정의
	while (i <= middle && j <= end) {
		if (src[i] <= src[j]) {
			sorted[s] = src[i];
			i++;
		} else {
			sorted[s] = src[j];
			j++;
		}
		s++;
	}
	if (i > middle) {
		// 남은 j(오른쪽)들 sorted 로 넣기.
		for (int t = j; t <= end; t++) {
			sorted[s] = src[t];
			s++;
		}
	}
	else {
		// 남은 i(왼쪽)들 sorted 로 넣기.
		for (int t = i; t <= middle; t++) {
			sorted[s] = src[t];
			s++;
		}
	}

	// 정렬된 배열을 원 배열로 옮기기
	for (int k = start; k <= end; k++) {
		src[k] = sorted[k];
	}
}

void mergeSort(vector<int> &src, int start, int end) {
	if(start < end){
		int middle = (start + end) / 2;
		// 반으로 계속해서 나누기 (logN)
		mergeSort(src, start, middle);
		mergeSort(src, middle + 1, end);
		// 나눈 것들을 오름차순으로 합치기
		merge(src, start, middle, end);
	}
}

int main() {
	vector<int> arr = { 2,5,1,6,7,3,4,8,9,12,11,10 };

	mergeSort(arr, 0, arr.size()-1);

	cout << "RESULT : ";
	print(arr);
	return 0;
}