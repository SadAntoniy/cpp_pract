#include <iostream>
using namespace std;

int main() {
	double n, a, b, x, y;
	double res = 0;

	cin >> n >> a >> b >> x >> y;

	if (a < b)
	{
		if (n > b) {
			res = n - (n * y) / 100;
			cout << res;
		}
		else if (n > a) {
			res = n - (n * x) / 100;
			cout << res;
		}
		else {
			cout << n;
		}
	}
}