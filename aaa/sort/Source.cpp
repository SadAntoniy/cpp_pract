#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

bool modul(int x, int y) {	
		if(abs(x) < abs(y))
			return true;
		return false;
}

void print_vec(vector <int>& v) {
	for (auto& i : v)
		cout << i << " ";
}

int main() {
	int N;
	vector <int> v;

	cin >> N;
	if (0 <= N || N <= 1000) {
		for (int i = 0; N > i; i++) {
			int n;
			cin >> n;
			if (-1000000 <= n || n <= 1000000) {
				v.push_back(n);
			}
		}
		sort(v.begin(), v.end(), modul);
		print_vec(v);
	}
	return 0;
}