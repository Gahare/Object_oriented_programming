#include <iostream>

using namespace std;

const int MAX = 100;

float fmemory[MAX];
int fmem_top = 0;
int pmemory[MAX];
int pmem_top = 0;

class Float
{
	int addr;
public:
	Float(float value)
	{
		addr = fmem_top;
		fmemory[fmem_top++] = value;
	}
	int operator&()
	{
		return addr;
	}
};

class ptrFloat
{
	int addr;
public:
	ptrFloat(int ptr)
	{
		addr = pmem_top;
		pmemory[pmem_top++] = ptr;
	}
	float& operator*()
	{
		return fmemory[pmemory[addr]];
	}
};

int main()
{
	Float varl = 1.234;
	Float var2 = 5.678;
	ptrFloat ptrl = &varl;
	ptrFloat ptr2 = &var2;
	cout << "*ptrl = " << *ptrl << endl;
	cout << "*ptr2 = " << *ptr2 << endl;
	*ptrl = 7.123; *ptr2 = 8.456;
	cout << "*ptrl = " << *ptrl << endl;
	cout << "*ptr2 = " << *ptr2 << endl;
}