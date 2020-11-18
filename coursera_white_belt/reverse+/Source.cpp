#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Reversed(vector<int> v) {

	reverse(begin(v), end(v));
	return v;
}