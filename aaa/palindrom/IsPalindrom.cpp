#include <iostream>
#include <string>
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