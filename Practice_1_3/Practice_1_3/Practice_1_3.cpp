#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int N = 100;

vector<int> fillVector(int);
void printVector(vector<int>);
void searchForIndex(vector<int>, int&);
vector<int> fillRandomVector(int);
int main() {
	int n, foundIndx, newElem;
	cout << "Enter the size of array in range (1, 99)";
	cin >> n;
	if (n <= 0 or n > N - 1) {
		cout << "Wrong";
		return 0;
	}
	vector<int> arr = fillVector(n);
	printVector(arr);
	searchForIndex(arr, foundIndx);
	if (foundIndx == -1) {
		cout << "Index error";
		return 0;
	}
	cout << "Index of element: " << foundIndx << "\nElement: " << arr[foundIndx] << endl;
	cout << "Input new element";
	cin >> newElem;
	arr.insert(arr.begin() + foundIndx, newElem);
	printVector(arr);
	cout << "Delete elem...\n";
	while (foundIndx != -1) {
		arr.erase(arr.begin() + foundIndx);
		searchForIndex(arr, foundIndx);
	}
	printVector(arr);
	return 0;
}

vector<int> fillVector(int n) {
	vector<int> arr(n);
	cout << "Fill arrray\n";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	return arr;
}

vector<int> fillRandomArray(int n) {
	vector<int> arr(n);
	cout << "Random fill array\n";
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10 + 1;
	}
	return arr;
}

void printVector(vector<int> arr) {
	cout << "Vector\n";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


void searchForIndex(vector<int> arr, int& foundIndx) {
	int numb;
	for (int i = 0; i < arr.size(); i++) {
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

