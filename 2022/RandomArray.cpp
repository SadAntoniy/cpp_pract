#include "iostream"
#include "ctime"

/*

The program fills the dynamic array with random numbers that should not be repeated
Also program find min and max from this array

*/

void print(int* arr, int size) {
	
	for (int i = 0; i < size; i++) {
		std::cout << arr[i];
		if (i != size-1) {
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void pull_arr(int* arr, int size, int b) {
	
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % b;
		int a = 0;		
		while (a != i) {
			if (arr[i] == arr[a]) {
				arr[i] = rand() % b;
				a = 0;
				continue;
			}	
			a++;
		}		
	}
}

void put_numbers(int& size, int& size_rand) {
	do {
		std::cout << "put k - size of massive" << std::endl;

		std::cin >> size;

		std::cout << "put c - number of rand" << std::endl;

		std::cin >> size_rand;

		std::cout << std::endl;
	} while (size > size_rand);
}

int min_val(int* arr, int size) {
	int minimum = arr[0];
	for (int i = 1; i < size; i++) {
		if (minimum > arr[i]) 
			minimum = arr[i];			
	}
	return minimum;
}

int max_val(int* arr, int size) {
	int maximum = arr[0];
	for (int i = 1; i < size; i++) {
		if (maximum < arr[i])
			maximum = arr[i];
	}
	return maximum;
}

int main() {

	srand(time(NULL));

	int k = 0;
	int c = 0;
	
	put_numbers(k, c);

	int* n = new int[k];

	pull_arr(n, k,c);

	print(n, k);

	std::cout << "min value is " << min_val(n, k) << std::endl;

	std::cout << "max value is " << max_val(n, k) << std::endl;
	
	delete []n;

	return 0;
}
