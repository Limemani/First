#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrome(string word) {
	string temp = word;
	for (int i = 0; i < word.size(); i++) {
		temp[word.size() - i - 1] = word[i];
	}
	if (temp == word) {
		return true;
	}
	else {
		return false;
	}
}

vector <string> SplitInToWords(string text) {
	vector <string> words;
	string word;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == ' ') {
			words.push_back(word);
			word = ""s;
		}
		else {
			word += text[i];
		}
	}
	words.push_back(word);
	return words;
}

vector <string> PalFilter(vector <string> words, int min_len) {
	vector <string> res;
	for (auto p: words) {
		if (p.size() >= min_len) {
			if (IsPalindrome(p)) {
				res.push_back(p);
			}
		}
	}
	return res;
}

void enter(vector <string> vec) {
	for (auto p : vec) {
		cout << p << endl;
	}
}

int main() {
	string bub;
	vector <string> pope;
	getline(cin, bub);
	pope = SplitInToWords(bub);
	pope = PalFilter(pope, 4);
	enter(pope);
}