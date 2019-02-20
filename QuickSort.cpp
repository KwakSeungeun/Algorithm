#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &src, int start, int end) {
	if (start >= end) {
		return;
	}
	int key = start;
	int i = start + 1,j = end;
	int temp;

	while (i<=j){
		// key위치보다 큰 값을 만날 때 까지
		while (i <= end && src[i] <= src[key]) {
			i++;
		}
		// key 위치보다 작은 값을 만날 때 까지
		while (j > start && src[j] >= src[key]) {
			j--;
		}
		if (i > j) {
			temp = src[j];
			src[j] = src[key];
			src[key] = temp;
		} else {
			temp = src[j];
			src[j] = src[i];
			src[i] = temp;	
		}
	}
	quickSort(src, start, j - 1);
	quickSort(src, j + 1, end);
	return;
}

int main() {
	vector<int> arr = { 2,5,1,6,7,10,3,4,8,9 };
	quickSort(arr, 0, arr.size() - 1);
	cout << "RESULT : ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	return 0;
}