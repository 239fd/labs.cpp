﻿#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	string s;
	vector<string> words;

	cout << "Enter the string: ";
	getline(cin, s);

	int i = 0;
	string new_word;
	while (i < s.length()) {
		if (s[i] != ' ') {
			new_word += s[i];
		}
		else {
			words.push_back(new_word);
			new_word = "";
		}
		i++;
	}
	words.push_back(new_word);

	sort(words.begin(), words.end());

	for (auto& d:words) {
		cout << d << " ";
	}
	words.clear();

}

//Все буквы в верзний регистр четные в 2 нечентыне в 1 все остальное в !