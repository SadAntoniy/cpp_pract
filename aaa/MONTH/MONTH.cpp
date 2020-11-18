#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<int> days_m = {  31, 28, 31,
							30, 31, 30,
							31, 31, 30,
							31, 30, 31 };
	vector<int> numb_of_cases(31);
	int month = 0;
	vector<string> causes(days_m[month], "");
	
	
	int q;
 	cin >> q;
	numb_of_cases.resize(days_m[month], 0);


	for (int j = 0; j < q; j++) {
		string cause;
		string s;
		int i;
		cin >> cause;
		if (cause == "ADD") {
			cin >> i >> s;
			if (i <= days_m[month] || i > 0) {
				causes[i - 1] += " " + s;
				numb_of_cases[i - 1] += 1;
			}
		}
		else if (cause == "DUMP") {
			cin >> i;			
			if (numb_of_cases[i - 1] > 0) {
				cout << numb_of_cases[i - 1]	;
				cout << causes[i - 1] << endl;
			}
			else if (numb_of_cases[i - 1] == 0) {
				cout << numb_of_cases[i - 1] << endl;
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
				int r = numb_of_cases[days_m[month - 1] - a];
				for (int k = 0; k < (days_m[month - 1] - days_m[month]); k++) {
					causes[days_m[month] - 1] += t;
					t = causes[days_m[month - 1] - ++a];
					
						if (!t.empty()) {
							numb_of_cases[days_m[month] - 1] += r;
						
					}
				}
				numb_of_cases.resize(days_m[month]);
				causes.resize(days_m[month]);
			}
			else if (days_m[month] > days_m[month - 1]) {
				for (int k = 0; k < (days_m[month] - days_m[month - 1]); k++) {
					causes.push_back("");
					numb_of_cases.push_back(0);
				}
			}
			else {
				
			}
		}
	}
	return 0;
}

