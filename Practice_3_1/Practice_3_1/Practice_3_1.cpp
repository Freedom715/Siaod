#include <iostream>
#include <string>
#pragma warning(disable: 4996)

using namespace std;

const int n = 256;

int main() {
	int i = 0, counter_word = 0, counter_numb = 0;
	char ps1[256], ps2[256], number;
	int indx_flag;
	cin.getline(ps1, 256);
	while (ps1[i] != '\0') {
		if (ps1[i] != ' ' or ps1[i] != ',') {
			indx_flag = i;
			if (isdigit(ps1[i])) {
				if (number and number == ps1[i]) {
					counter_numb += 1;
				}
				else {
					number = ps1[i];
				}
			}
			counter_word += 1;
		}
		else {
			

		}
	}
}

void erase() {

}

