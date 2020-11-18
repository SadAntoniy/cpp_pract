#include <iostream>
#include <map>

using namespace std;

map <char, int> BuildCharCounter(map<char, int>& m, const string& s) {
	for (int i = 0; i < s.size(); i++) {
		++m[s[i]];

	}
	return m;
}

int main() {

	string first_word;
	string second_word;

	map<char, int> how_many_chars_first;
	map<char, int> how_many_chars_second;
	
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> first_word >> second_word;

		BuildCharCounter(how_many_chars_first, first_word);
		BuildCharCounter(how_many_chars_second, second_word);


		if (how_many_chars_first == how_many_chars_second)
			cout << "YES";
		else
			cout << "NO";
		how_many_chars_first.clear();
		how_many_chars_second.clear();
		cout << endl;
	}


}