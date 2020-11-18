#include <iostream>
using namespace std;

int main() {
	int a, b;
	int res = 0;
	cin >> a >> b;

	for (; b >= a; a++)
	{
		res = a % 2;
		if (res == 0) {
			cout << a << " ";
		}
	}
	
}