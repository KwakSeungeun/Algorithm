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

int main(void) {
	vector<int> arr = { 2,5,12,6,7,3,4,8,9,1,11,10 };
	const int n = arr.size();
	// Max heap 만들기
	for (int i = 1; i < n; i++) {
		int child = i;
		do {
			int root = (child - 1) / 2;
			if (arr[root] < arr[child]) {
				int temp = arr[root];
				arr[root] = arr[child];
				arr[child] = temp;
			}
			child = root;
		} while (child != 0);
	}

	// root와 heap의 마지막과 바꿔 오름차순으로 정리 => heap의 크기를 줄임.
	for (int i = n-1; i >= 0; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		int root = 0;
		int child = 1;
		do{
			child = 2 * root + 1; // 왼쪽 자식
			if (child < i-1 && arr[child] < arr[child + 1]) {
				child++;
			}
			if (child < i &&arr[root] < arr[child]) {
				temp = arr[root];
				arr[root] = arr[child];
				arr[child] = temp;
			}
			root = child;
		} while (child<i);
	}

	cout << "Result : ";
	print(arr);
	return 0;
}