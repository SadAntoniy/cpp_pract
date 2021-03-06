#include <iostream>
#include <map>

using namespace std;

void PrintMap(const map<string, string>& map) {
	for (const auto& m : map) {
		cout << m.first << "/" << m.second << " ";
	}
	cout << endl;
}

int main() {

	map<string, string> directory_of_country;

	string request;
	int Q;
	cin >> Q;

	for (int i = 0; i < Q; i++) {
		string country;
		string capital;
		cin >> request;
		if (request == "CHANGE_CAPITAL") {
			cin >> country >> capital;

			if (directory_of_country[country].empty()) {
				directory_of_country[country] = capital;
				cout << "Introduce new country " << country << " with capital " << capital << endl;
			}
			else if (directory_of_country[country] == capital) {
				cout << "Country " << country << " hasn't changed its capital " << endl;
			}
			else if (directory_of_country[country] != capital) {
				string old_capital = directory_of_country[country];
				directory_of_country[country] = capital;
				cout << "Country " << country << " has changed its capital from " << old_capital << " to " << capital << endl;

			}
		}
		if (request == "RENAME") {

			string old_country; //= c.first;
			cin >> old_country >> country;

			
				if (old_country == country) {

					cout << "Incorrect rename, skip" << endl;

				}				
				else if (!directory_of_country.count(old_country)/*directory_of_country[old_country].empty()*/) {

					//directory_of_country.erase(old_country);
					cout << "Incorrect rename, skip" << endl;

				}
				else if(directory_of_country.count(country)){
					cout << "Incorrect rename, skip" << endl;
				}
				else if (directory_of_country.count(old_country) || old_country == directory_of_country[old_country]) {

					directory_of_country[country] = directory_of_country[old_country];
					directory_of_country.erase(old_country);
					cout << "Country " << old_country << " with capital " << directory_of_country[country] << " has been renamed to " << country << endl;
				}
			}		
		
		if (request == "ABOUT") {
			cin >> country;
			if (directory_of_country[country].empty()) {
				cout << "Country " << country << " doesn't exist" << endl;
				directory_of_country.erase(country);
			}
			else
				cout << "Country " << country << " has capital " << directory_of_country[country] << endl;
		}
		if (request == "DUMP") {
			if (directory_of_country.empty())
				cout << "There are no countries in the world" << endl;
			else
				PrintMap(directory_of_country);
		}
	}
	return 0;
}
