//�ٷ� ���� �ִ� ���� ���Ͽ� �� ���� ���� ������.(���� ū �� ���� �ں��� ����)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> arr = { 2,5,1,6,7,10,3,4,8,9 };
	int temp;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size()-i-1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << "RESULT : ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	return 0;
}