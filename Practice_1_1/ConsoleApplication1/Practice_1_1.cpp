#include <iostream>
#include <cmath>

using namespace std;

const int N = 100;

int* fillArray(int*, int);
void printArray(int*, int);
void searchForIndex(int*, int, int&);
int* fillRandomArray(int*, int);
int* insert(int*, int&, int, int);
int* erase(int*, int&, int);
int main() {
	int n, foundIndx, newElem;
	int arr[N];
	cout << "Enter the size of array in range (1, 99)";
	cin >> n;
	if (n <= 0 or n > N - 1) {
		cout << "Wrong";
		return 0;
	}
	printArray(fillArray(arr, n), n);
	searchForIndex(arr, n, foundIndx);
	cout << foundIndx << endl;
	if (foundIndx == -1) {
		cout << "Index error";
		return 0;
	}
	cout << "Index of element: " << foundIndx << "\nElement: " << arr[foundIndx] << endl;
	cout << "Input new element";
	cin >> newElem;
	printArray(insert(arr, n, foundIndx, newElem), n);
	cout << "Delete elem...\n";
	printArray(erase(arr, n, foundIndx), n);
	return 0;
}

int* fillArray(int* arr, int n) {
	cout << "Fill arrray\n";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	return *&arr;
}

int* fillRandomArray(int* arr, int n) {
	cout << "Random fill array\n";
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10 + 1;
	}
	return *&arr;
}

void printArray(int* arr, int n) {
	cout << "Array\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int* insert(int* arr, int& n, int foundIndx, int newElem) {
	n++;
	for (int i = n; i >= foundIndx; i--) arr[i] = arr[i - 1];
	arr[foundIndx] = newElem;
	return arr;
}

int* erase(int* arr, int& n, int foundIndx) {
	while (foundIndx != -1) {
		for (int i = foundIndx; i < n - 1; i++) arr[i] = arr[i + 1];
		n -= 1;
		searchForIndex(arr, n, foundIndx);
	}
	return arr; 
}

void searchForIndex(int* arr, int n, int& foundIndx) {
	int numb;
	for (int i = 0; i < n; i++) {
		numb = arr[i];
		foundIndx = 0;
		long a = floor(log10(numb)) + 1;
		for (int j = 1; j <= a - 1; j++) {
			if (int(numb / pow(10, a - 1)) <= int(numb % int(pow(10, j)) / pow(10, j - 1))) {
				foundIndx = -1;
			}
		}
		if (foundIndx != -1) {
			foundIndx = i;
			return;
		}
	}
}

