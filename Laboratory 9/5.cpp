#include <iostream>

using namespace std;

const int SIZE = 9;

void addarrays(const float* firstArray, const float* secondArray, float* thirdArray, int size)
{
	for(int i = 0; i < size; i++) {
		*(thirdArray + i) = *(firstArray + i) + *(secondArray + i);
	}
}

int main()
{
	float arr1[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
	float arr2[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
	float arr3[SIZE] = {};
	addarrays(arr1, arr2, arr3, SIZE);

	cout << "arr3 = ";
	for(int i = 0; i < SIZE; i++) {
		cout << *(arr3+i) << " ";
	}
}