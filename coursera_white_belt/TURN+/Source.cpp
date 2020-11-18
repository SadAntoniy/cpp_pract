#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector <int> turn;
	int n;
	int a;
	int k;
	int q = 0;
	string s;
	cin >> n;
	for (int i = 0; i != n; i++) {
		cin >> s;
		if (s == "COME") {
			cin >> a;
			if (a > 0) {
				for (int j = 0; j < a; j++) {
					turn.push_back(false);
				}
			}
			else if (a < 0) {
				k = -a;
				for (int j = 0; j < k; j++) {
					turn.pop_back();
				}
			}
			else {

			}
		}
		else if (s == "WORRY") {
			cin >> a;
			if (a >= 0 && a < turn.size()) {
				turn[a] = true;
			}
		}
		else if (s == "QUIET") {
			cin >> a;
			if (a >= 0 && a < turn.size()) {
				turn[a] = false;
			}
		}
		else if (s == "WORRY_COUNT") {
			for (auto z : turn) {
				if (z == true) {
					q++;
				}
			}
			cout << q << endl;
		}
		q = 0;
	}
}