#include <iostream>
#include <string>
#include <IsPalindrom>
using namespace std;

bool IsPalindrom(string palindrom) {

	int lenght = palindrom.length();
	for (int i = 0; i < palindrom.length() / 2; i++) {
		if (palindrom[i] == palindrom[palindrom.length() - i - 1])
		{
			
		}
		else {
			return false;
		}
	}
	return true;

}

int main() {
	string str;
	cin >> str;
	IsPalindrom(str);
	cout << IsPalindrom(str);
	return 0;
}