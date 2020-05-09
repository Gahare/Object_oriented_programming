#include <iostream>

using namespace std;

class Array {
	int *ptr;
	int size;
public:
	Array(int s) {
		size = s;
		ptr = new int[s];
	}
	Array(const Array &s) {
		size = s.size;
		ptr = new int[size];
		for (int i = 0; i < size; i++) {
			*(ptr + i) = *(s.ptr + i);
		}
	}
	~Array() {
		delete[] ptr;
	}
	int &operator[](int j) {
		return *(ptr + j);
	}
	Array &operator=(const Array &s) {
		*this = Array(s);
		return *this;
	}
};

int main() {
	const int ASIZE = 10;
	Array arr1(ASIZE);

	for (int j = 0; j < ASIZE; j++) {
		arr1[j] = j * j;
	}
	Array arr2(arr1);
	arr2[0] = 555;
	Array arr3 = arr1;
	cout << "arr1 = ";
	for (int j = 0; j < ASIZE; j++) {
		cout << arr1[j] << ' ';
	}

	cout << "\narr2 = ";
	for (int j = 0; j < ASIZE; j++) {
		cout << arr2[j] << ' ';
	}

	cout << "\narr3 = ";
	for (int j = 0; j < ASIZE; j++) {
		cout << arr3[j] << ' ';
	}

	cout << endl;
	return 0;
}
