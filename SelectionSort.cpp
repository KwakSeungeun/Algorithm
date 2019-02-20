//가장 작은 것을 선택하여 맨 앞으로 보내기.
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> arr = { 2,5,1,6,7,10,3,4,8,9 };
	int temp, min, index;
	for (int i = 0; i < arr.size(); i++) {
		min = 9999;
		for (int j = i; j < arr.size(); j++) {
			if (min > arr[j]) { 
				min = arr[j]; 
				index = j;
			}
		}
		temp = arr[index];
		arr[index] = arr[i];
		arr[i] = temp;
	}
	cout << "RESULT : " << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	return 0;
}