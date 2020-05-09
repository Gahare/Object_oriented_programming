#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int *ap[10];

	for(int i = 1; i < 11; i++) {
		*(ap + i - 1) = new int[10];
		for(int j = 1; j < 11; j++) {
			*(*(ap + i - 1) + j - 1) = i * j;
		}
	}

	for(int i = 1; i < 11; i++) {
		for(int j = 1; j < 11; j++) {
			cout << setw(5) << *(*(ap + i - 1) + j - 1);
		}
		cout << endl;
	}

	return 0;
}