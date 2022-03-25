#include <iostream>
using namespace std;
void inputArray(int**, int);
void outputArray(int**, int);
void findMaxValue(int**, int, int&);

int main() {
	int n, maxValue = 0;
	bool r;
	cout << "Enter size of matrixx: ";
	cin >> n;
	if (n <= 0 or n > 10) {
		cout << "Wrong n";
		return 0;
	}
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n + 1];
	}
	inputArray(arr, n);
	outputArray(arr, n);
	findMaxValue(arr, n, maxValue);
	cout << maxValue;
}

void inputArray(int** arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " row:\n";
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

void outputArray(int** arr, int n) {
	cout << "matrix\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void findMaxValue(int** arr, int n, int& maxValue) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j and n - i - 1 != j) {
				if (maxValue < arr[i][j]) {
					maxValue = arr[i][j];
				}
			}
		}
	}
}