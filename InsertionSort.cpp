// 각 숫자를 적절한 위치로 보내기.
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> arr = { 2,5,1,6,7,10,3,4,8,9 };
	int temp, j;
	for (int i = 0; i < arr.size(); i++) {
		j = i;
		while (j>0 && arr[j] < arr[j-1]){
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
	
	cout << "RESULT : ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	return 0;
}