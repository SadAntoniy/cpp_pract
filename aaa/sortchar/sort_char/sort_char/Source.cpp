#include <iostream>
#include <vector>
#include <algorithm>
#include <locale>
#include <cctype>
using namespace std;

bool lowcases(string s1, string s2) {
	int i = 0, j = 0;
	if (s1.size() >= s2.size()) {
		for (int k = 0; (s1.size(), s2.size()) > k; k++) {
			if (s1 == s2) {
				return false;
			}
			else if (tolower(s1[i]) < tolower(s2[j])) {
				return true;
			}
			else if (tolower(s1[i]) == tolower(s2[j])) {
				++i;
				++j;
			}
			else {
				return false;
			}
		}
	}
	return false;
}

void print_vec(const vector <string> & s)
{
	for (const auto& i : s)
		cout << i << " ";
}

int main() 
{
	int N;
	vector <string> s;
	cin >> N;

	if (0 <= N || N <= 1000) {
		for (int i = 0; N > i; i++) {
			string S;
			cin >> S;

			if (S.size() >= 0 || S.size() <= 15) {
				s.push_back(S);
			}
		}		
	}

	sort(s.begin(), s.end(), lowcases);
	print_vec(s);
	
	

	return 0;		
}