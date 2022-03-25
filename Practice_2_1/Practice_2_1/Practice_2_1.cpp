#include <iostream>
using namespace std;
const int row = 10;
void inputArray(int[row][row], int);
void outputArray(int[][row], int);
void findMaxValue(int[][row], int, int&);

int main() {
	int n, maxValue = 0;
	bool r;
	cout << "Enter size of matrixx: ";
	cin >> n;
	if (n <= 0 or n > 10) {
		cout << "Wrong n";
		return 0;
	}
	int arr[row][row];
	inputArray(arr, n);
	outputArray(arr, n);
	findMaxValue(arr, n, maxValue);
	cout << maxValue;
}

void inputArray(int arr[row][row], int n) {
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " row:\n";
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

void outputArray(int arr[row][row], int n) {
	cout << "matrix\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void findMaxValue(int arr[][row], int n, int& maxValue) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j and n - i - 1 != j) {
				cout << arr[i][j] << " ";
				if (maxValue < arr[i][j]) {
					maxValue = arr[i][j];
				}
				cout << endl;
			}
		}
	}
}