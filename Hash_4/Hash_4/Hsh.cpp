#include <iostream>

int main() {
	int temp;
	int hash[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int num[7] = { 86, 90, 27, 29, 38, 39, 40 };
	for (int i = 0; i < 7; i++) {
		temp = num[i] % 7;
		while (true) {
			if (hash[temp] == 0) 
			{
				hash[temp] = num[i];
				break;
			}
			else temp = (temp + 1) % 7;
		}
	}
	for (int i = 0; i < 7; i++) {
		std::cout << hash[i] << " ";
	}
}