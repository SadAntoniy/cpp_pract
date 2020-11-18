#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SrednAriphm(vector<int> v, int a, int& mid) {

	for (auto x : v) {
		mid += x;
	}
	mid = mid / a;
}

int main() {
	int midl = 0;
	int n;
	int i = 0;
	int x;
	int j = 0;
	int size = 0;
	cin >> n;
	int b = n;
	vector<int> temp_days;
	vector<int> more_than_middle;

	for (int a = 0; n != 0; --n) {
		cin >> x;
		temp_days.push_back(x);
	}

	SrednAriphm(temp_days, b, midl);

	for (auto v : temp_days) {
		if (v > midl) {
			more_than_middle.push_back(v);
			size++;
		}
		else if (v <= midl) {
			more_than_middle.push_back(0);
		}

	}
	cout << size << endl;
	for (auto h : more_than_middle) {
		if (h > 0) {
			cout << j << " ";
		}
		j++;
	}

	return 0;
}