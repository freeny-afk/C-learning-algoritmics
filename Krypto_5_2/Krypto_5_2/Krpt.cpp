#include <iostream>
#include <string>

int main() {
	int num, it = 0;
	std::string name;
	char alf[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char alfk[26] = { 'I','L','O','V','E','U','M','Y','S','B','D','X','R','W','K','A','C','T','F','Z','G','N','Q','H','P' };
	std::getline(std::cin, name);

	for (int i = 0; i < name.size(); i++) {
		if (name[i] != ' ') {
			for (int j = 0; j < 25; j++) {
				if (alf[j] == name[i]) {
					it = j;
				}
			}
			name[i] = alfk[it];
			std::cout << name[i];
		}
		else {
			std::cout << " " << name[i];
			continue;
		}
	}

}