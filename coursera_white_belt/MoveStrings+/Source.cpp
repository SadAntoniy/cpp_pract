#include <iostream>
#include < vector>
#include <string>

using namespace std;

void MoveStrings(vector<string> source, vector <string>& destination) {
	for (auto x : source) {
		destination.push_back(x);
	}
	source.clear();
}

int main() {
	vector<string> source = { "a", "b", "c" };
	vector<string> destination = { "z" };
	MoveStrings(source, destination);
	cout << destination.size();
	return 0;
}