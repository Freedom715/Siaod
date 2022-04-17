#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, counter = 0, numb1, numb2;
	cin >> N;
	vector <vector <int>> sp;
	sp.resize(1);
	sp[0].resize(2);
	cin >> sp[0][0] >> sp[0][1];
	for (int i = 1; i < N; i++) {
		cin >> numb1 >> numb2;
		if (numb1 != 0 and numb2 != 0) {
			for (int j = 0; j < sp.size(); j++) {
				if (numb1 < 0 and 0 < sp[j][0] and numb2 > 0 and sp[j][1] > 0) {
					counter+= 1;
				}
				else if (sp[j][1] < 0 and 0 < numb2 and numb1 > 0 and sp[j][0] > 0) {
					counter += 1;
				}
				else if (sp[j][0] < 0 and 0 < numb1 and numb2 < 0 and sp[j][1] < 0) {
					counter += 1;
				}
				else if (numb2 < 0 and 0 < sp[j][1] and numb1 < 0 and sp[j][0] < 0) {
					counter += 1;
					cout << numb1 << ", " << numb2 << " - " << sp[j][0] << ", " << sp[j][1] << endl;
				}
			}
			sp.resize(sp.size() + 1);
			sp[sp.size() - 1].resize(2);
			sp[sp.size() - 1][0] = numb1;
			sp[sp.size() - 1][1] = numb2;

		}
	}
	cout << counter << " " << sp.size();
	
	return 0;
}