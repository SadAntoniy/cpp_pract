#include <iostream>
#include <ctime>

template <typename T>
void CopyArray(T *arr1, T *arr2, int size) 
{
	for (int i = 0; i < size; i++)
	{
		arr2[i] = arr1[i];
		arr1[i] += 1;
	}
}

template <typename T1>
T1 PullArray( T1* const arr, int size)
{
	for (int i = 0; i < size; i++) 
	{
		arr[i] = (double)rand()/RAND_MAX*15;
	}
	return *arr;
}

template <typename T2>
void Print( T2 const*arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;
}

int main() 
{
	srand(time(NULL));
	int size;
	std::cin >> size;

	double* firstArr = new double[size];
	double* secondArr = new double[size];
	int* firstArrInt = new int[size];
	int* secondArrInt = new int[size];

	PullArray(firstArr, size);
	PullArray(firstArrInt, size);

	CopyArray(firstArr, secondArr, size);
	CopyArray(firstArrInt, secondArrInt, size);

	Print(firstArr, size);
	Print(secondArr, size);

	Print(firstArrInt, size);
	Print(secondArrInt, size);

	delete[] firstArr;
	delete[] secondArr;
	delete[] firstArrInt;
	delete[] secondArrInt;

	return 0;

}