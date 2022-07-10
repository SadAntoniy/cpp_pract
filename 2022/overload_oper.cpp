#include <iostream>
#include <ctime>

using namespace std;

class q
{
public:

	q(int size)
	{
		this->size = size;
		this->arr = new int[this->size];

		for (int i = 0; i < size; i++) {
			arr[i] = rand()%10;
		}
	}

	q(const q& other)
	{
		this->size = other.size;

		this->arr = new int[other.size];

		for (int i = 0; i < other.size; i++) {
			this->arr[i] = other.arr[i];
		}
	}

	~q()
	{
		delete[] arr;
	}

	q operator + (const q& other)
	{
		q temp(this->size);
		
		temp.arr = new int[temp.size];

		for (int i = 0; i < this->size; i++) 
		{
			temp.arr[i] = this->arr[i] + other.arr[i];
		}
		return temp;
	}

	q operator * (const q& other)
	{
		q temp(this->size);

		temp.arr = new int[temp.size];

		for (int i = 0; i < this->size; i++)
		{
			temp.arr[i] = this->arr[i] * other.arr[i];
		}
		return temp;
	}

	int & operator [] (int i)
	{
		return arr[i];
	}

	void Print()
	{
		for (int i = 0; i < size; i++) {
			cout << arr[i] << endl;
		}
		cout  << endl;
	}

private:
	int size;
	int *arr;

	friend void change_size(q& obj);
};

void change_size(q & obj)
{
	obj.size++;
	int *temp = new int[obj.size];

	for (int i = 0; i < obj.size; i++)
	{
		if (obj.size - 1 != i)
			temp[i] = obj.arr[i];
		else
			temp[i] = rand() % 10;		
	}

	delete[] obj.arr;
	obj.arr = new int[obj.size];

	for (int i = 0; i < obj.size; i++)
	{
		obj.arr[i] = temp[i];
	}

	delete[] temp;
}

int main()
{
	srand(time(NULL));

	q a(10);
	q b(a);
	q c = a + b;

	a.Print();
	b.Print();
	c.Print();

	cout << a[2] << endl << endl;

	change_size(a);
	a.Print();

	return 0;
}
