#include <iostream>

using namespace std;

class Counter
{
protected:
	unsigned int count;
public:
	Counter() : count(0) { }
	explicit Counter(int c) : count(c) { }
	unsigned int get_count() const
	{
		return count;
	}
	Counter operator ++ ()
	{
		return Counter(++count);
	}
};

class CountDn : public Counter
{
public:
	CountDn() : Counter() { }
	explicit CountDn(int c) : Counter(c) { }
	CountDn(Counter counter) {
		count = counter.get_count();
	}
	CountDn operator -- ()
	{
		return CountDn(--count);
	}
	CountDn operator -- (int)
	{
		return CountDn(count--);
	}
	using Counter:: operator ++;
	CountDn operator ++ (int)
	{
		return CountDn(count++);
	}
};

int main()
{
	CountDn c1;
	CountDn c2(100);

	cout << "c1 = " << c1.get_count() << endl;
	cout << "c2 = " << c2.get_count() << endl;

	CountDn c3;
	c3 = c1++;
	cout << "c3 = c1++ = " << c3.get_count() << " (c1 = " << c1.get_count() << ")" << endl;
	c3 = ++c1;
	cout << "c3 = ++c1 = " << c3.get_count() << " (c1 = " << c1.get_count() << ")" << endl;
	c3 = c2--;
	cout << "c3 = c2-- = " << c3.get_count() << " (c2 = " << c2.get_count() << ")" << endl;
	c3 = --c2;
	cout << "c3 = --c2 = " << c3.get_count() << " (c2 = " << c2.get_count() << ")" << endl;
	return 0;
}
