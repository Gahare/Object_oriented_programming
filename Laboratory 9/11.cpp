#include <iostream>
#include <iomanip>

using namespace std;

class multidimensionalArray
{
	int *ptr[10];
public:
	multidimensionalArray()
	{
		for(int i = 0; i < 10; i++) {
			*(ptr + i) = new int[10];
		}
	}
	int& operator[](int index)
	{
		return *(*(ptr + index / 10) + index % 10);
	}
};

int main()
{
	multidimensionalArray arr;
	for(int i = 0; i < 100; i++) {
		arr[i] = i + 1;
	}

	for(int i = 0; i < 100; i++) {
		if(i % 10 == 0) {
			cout << endl;
		}
		cout << setw(4) << arr[i];

	}

	return 0;
}