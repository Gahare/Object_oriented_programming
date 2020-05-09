#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int a1[10], a2[10], a3[10], a4[10], a5[10], a6[10], a7[10], a8[10], a9[10], a10[10];
	int *ap[] = {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10};

	for(int i = 1; i < 11; i++) {
		for(int j = 1; j < 11; j++) {
			ap[i - 1][j - 1] = i * j;
		}
	}

	for(int i = 1; i < 11; i++) {
		for(int j = 1; j < 11; j++) {
			cout << setw(5) << ap[i - 1][j - 1] ;
		}
		cout << endl;
	}

	return 0;
}