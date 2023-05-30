#include <iostream>
int main() {
	std::string word, s;
	std::cin >> word;
	std::cout << "\n";
	int c = 0, counthsh = 0;
	char* strs = new char[word.size()];
	int* hash = new int[word.size()];
	for (int i = 0; i < word.size(); i++) {
		strs[i] = '0';
	}

	for (int i = 0; i < word.size(); i++) {
		if (strs[i] == '0' and strs[i] != word[i]) {
				strs[i] = word[i];
				hash[i] = 1;
		}
	}

	for (int i = 0; i < word.size(); i++) {
		c = 0;
		while (c != i) {
			if (hash[i] > hash[c]) {
				hash[c] = hash[i]; break;
			}
			if (strs[i] == word[c] and i != c) {
				hash[c] += 1;
				break;
			}
			c++;
		}
		if (hash[c] <= 1) {
			counthsh++;
			std::cout << "'" << strs[i] << "' ";
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < counthsh; i++) {
			std::cout << "'" << hash[i] << "' ";
	}
}