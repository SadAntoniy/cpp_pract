#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a;
	int res;
	cin >> a;
	vector <int> bin;
	while (a > 0) {
		res = a % 2;
		a /= 2;
		bin.push_back(res);
	}
	reverse(bin.begin(), bin.end());

	for (auto x : bin) {
		cout << x;
	}
	
}