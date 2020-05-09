#include <iostream>
#include <string>
using namespace std;

class publication                     // base class
{
	string title;
	float price;
public:
	void getdata()
	{
		cout << "\nEnter title:"; cin >> title;
		cout << "Enter price:"; cin >> price;
	}
	void putdata() const
	{
		cout << "\nTitle:" << title;
		cout << "\nPrice:" << price;
	}
};

class book : private publication      // derived class
{
	int pages;
public:
	void getdata()
	{
		publication::getdata();
		cout << "Enter number of pages:"; cin >> pages;
	}
	void putdata() const
	{
		publication::putdata();
		cout << "\nPages:" << pages;
	}
};

class tape : private publication      // derived class
{
private:
	float time;
public:
	void getdata()
	{
		publication::getdata();
		cout << "Enter playing time:"; cin >> time;
	}
	void putdata() const
	{
		publication::putdata();
		cout << "\nPlaying time:" << time;
	}
};

int main()
{
	book book1;
	tape tape1;

	book1.getdata();
	tape1.getdata();

	book1.putdata();
	tape1.putdata();
	cout << endl;
}