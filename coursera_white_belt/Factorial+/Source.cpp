#include <iostream>
#include <vector>
using namespace std;

int Factorial(int x) {
	int res = 1;
	int i = 0;
		if (x < 0) {
			return 1;
		}
		while (i != x)
		{
			i++;
			res *= i;			
		}
	return res;
}

int main() {
	int a;
	vector<int> v(4);
	cin >> a;
	if (a >= -10 && a <= 10) {
		Factorial(a);
		cout << Factorial(a);
	}	
	cout << v.size();
	v[5] = 0;
	cout << endl;
	cout << v.size();
	return 0;
}