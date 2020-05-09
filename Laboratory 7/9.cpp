#include <iostream>
#include <process.h>

using namespace std;

const int LIMIT = 100;

class safearray {
private:
	int arr[LIMIT];
public:
	int& operator[](int n) {
		if(n < 0 || n >= LIMIT) {
			cout << "\nIncorrect index!";
			exit(1);
		}
		return arr[n];
	}
};

int main() {
	safearray arr;
	int top, bottom, bottom2, difference = 0;
	cout << "Enter the bottom border of the array:"; cin >> bottom;
	cout << "Enter the top border of the array:"; cin >> top;

	difference = top - 99;
	bottom2 = bottom;

	for(int i = bottom-difference; i <= top-difference; i++) {
		arr[i] = (bottom2++) * 10;
	}

	for(int i = bottom-difference; i <= top-difference; i++) {
		cout << "Element " << bottom++ << " equal " << arr[i] << endl;
	}

	return 0;
}