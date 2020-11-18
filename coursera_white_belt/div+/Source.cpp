#include <iostream>
using namespace std;

int main() {
	int a, b;
	int res = 0;
	
	cin >> a >> b;
	if (a > 0 || a < 1000000 || b > 0 || b < 1000000) {
		if (b == 0)
		{
			cout << "Impossible" << endl;
		}
		else {
			res = a / b;
			cout << res;
		}
	}

	
}