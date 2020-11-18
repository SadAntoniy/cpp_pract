/* Якшо а = 0, то Bx = -C () x = -C / B
	if B = 0, Ax^2 = -C () x = -sqrt(C / A)
	if C = 0, Ax^2 + Bx = 0 () Ax + B = 0 () x = -B / A
	if D < 0, STOP!
	if D = 0, we have 1 x
	if D > 0, we have 1 and 2 x
	if A = 0 () B = 0, C = 0;
	if A = 0 () C = 0, Bx = 0 () x = 0;
	if B = 0 () C = 0, Ax^2 = 0 () x = 0;
*/


#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double a, b, c;
	double D = 0;
	double x1 = 0;
	double x2 = 0;
	double res = 0;
	cin >> a >> b >> c;
	D = b * b - 4 * a * c;

	if ((a == 0 && b == 0) || (a == 0 && c == 0) || (b == 0 && c == 0)) {
		x1 = 0;
		cout << x1;
	}
	else if (a == 0 && b != 0 && c != 0) {
		x1 = -(c / b);
		cout << x1;
	}
	else if (b == 0 && a != 0 && c != 0) {
		x1 = -sqrt(c / a);
		x2 = sqrt(c / a);
		cout << x1 << " " << x2;
	}
	else if (c == 0 && a != 0 && b != 0) {
		res = sqrt(D);
		x1 = (-b + res) / (2 * a);
		x2 = (-b - res) / (2 * a);
		cout << x1 << " " << x2;
	}
	else if (D > 0) {
		res = sqrt(D);
		x1 = (-b + res) / (2 * a);
		x2 = (-b - res) / (2 * a);
		cout << x1 << " " << x2;
	}
	else if (D == 0) {
		res = sqrt(D);
		x1 = (-b + res) / (2 * a);
		cout << x1;
	}

	return 0;
}
