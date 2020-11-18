#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> PalindromFilter(vector<string> words, int minLenght) {

	vector<string> palindrom;
	for (auto x : words) {
		if (words.size() >= minLenght && IsPalindrom(words)); {
			palindrom.push_back(x);
		}
	}
	return words;
}