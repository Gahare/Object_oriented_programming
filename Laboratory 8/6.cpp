#include <iostream>

using namespace std;

const int LIMIT = 100;

class safearay
{
protected:
	int arr[LIMIT];
	int top;
	int bottom;
public:
	int& operator [](int n)
	{
		if( n < bottom || n > top || n >= LIMIT || n < 0)
		{
			cout << "Index out of bounds";
			exit(1);
		}
		return arr[n];
	}
};

class safearray1 : public safearay
{
public:
	safearray1(int b, int t)
	{
		top = t; bottom = b;
	}
};

int main()
{
	int lowerArrayBorder;
	int upperArrayBorder;

	cout << "Enter the bottom border in the array:"; cin >> lowerArrayBorder;
	cout << "Enter the top border of the array:"; cin >> upperArrayBorder;

	if(lowerArrayBorder > upperArrayBorder)
	{
		swap(lowerArrayBorder, upperArrayBorder);
	}

	int lower = lowerArrayBorder;
	safearray1 sf1(lowerArrayBorder, upperArrayBorder);

	for(int i = lowerArrayBorder; i <= upperArrayBorder; i++)
	{
		sf1[i] = (lower++) * 10;
	}

	cout << "The index range is " << lowerArrayBorder << " - " << upperArrayBorder << endl;

	char ch;
	do {
		int indx;
		cout << "Enter the index in the array to display it:"; cin >> indx;
		cout << "arr[" << indx << "] = " << sf1[indx] << endl;
		cout << "Would you like to countinue(y/n).."; cin >> ch;
	}while(ch != 'n');

}