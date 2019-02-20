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
	int i = start; // ���� ����
	int j = middle + 1; // ������ ����
	int s = start; //sorted �Լ� ����
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
		// ���� j(������)�� sorted �� �ֱ�.
		for (int t = j; t <= end; t++) {
			sorted[s] = src[t];
			s++;
		}
	}
	else {
		// ���� i(����)�� sorted �� �ֱ�.
		for (int t = i; t <= middle; t++) {
			sorted[s] = src[t];
			s++;
		}
	}

	// ���ĵ� �迭�� �� �迭�� �ű��
	for (int k = start; k <= end; k++) {
		src[k] = sorted[k];
	}
}

void mergeSort(vector<int> &src, int start, int end) {
	if(start < end){
		int middle = (start + end) / 2;
		// ������ ����ؼ� ������ (logN)
		mergeSort(src, start, middle);
		mergeSort(src, middle + 1, end);
		// ���� �͵��� ������������ ��ġ��
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