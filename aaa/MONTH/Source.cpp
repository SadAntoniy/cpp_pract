#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<int> days_m = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	vector<int> v1(31);
	int month = 0;
	vector<string> causes(days_m[month], "");
	int i;
	string cause;
	string s;
	int q;
	cin >> q;
	v1.resize(days_m[month], 0);


	for (int j = 0; j < q; j++) {
		cin >> cause;
		if (cause == "ADD") {
			cin >> i >> s;
			if (i <= days_m[month] || i > 0) {
				causes[i - 1] += " " + s;
				v1[i - 1] += 1;
			}
		}
		else if (cause == "DUMP") {
			cin >> i;
			
				if (v1[i - 1] != 0) {
					cout << v1[i - 1];
					cout << causes[i - 1] << endl;
				}
				else if (v1[i - 1] == 0) {
					cout << v1[i - 1] << endl;
				}
			
		}



		else if (cause == "NEXT") {
			month++;
			if (month > 11) {
				month = 0;
			}	else
			if (days_m[month] < days_m[month - 1]) {
				int a = 1;
				string t = causes[days_m[month - 1] - a];
				int r = v1[days_m[month - 1] - a];
				for (int k = 0; k < (days_m[month - 1] - days_m[month]); k++) {
					causes[days_m[month] - 1] += t;
					t = causes[days_m[month - 1] - ++a];
					if (!t.empty()) {
						v1[days_m[month] - 1] += r;
					}

				}
				v1.resize(days_m[month]);
				causes.resize(days_m[month]);
			}
			else if (days_m[month] > days_m[month - 1]) {
				for (int k = 0; k < (days_m[month] - days_m[month - 1]); k++) {
					causes.push_back("");
					v1.push_back(0);
				}
			}
			else {
				
			}



		}
	}


	return 0;
}

