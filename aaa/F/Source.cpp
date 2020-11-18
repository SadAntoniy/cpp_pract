#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	int i;
	int b = 0;
	cin >> a;

	for (i = 0; i < a.size(); ++i) {
		if (a[i] == 'f') {
			b++;
			if (b == 2) {
				break;
			}
		}
		
	}

		if (b == 0)
		{
			cout << -2;
		}
		else if (b == 1) {
			cout << -1;
		}
		else {
			cout << i;
		}
		
		
	
}