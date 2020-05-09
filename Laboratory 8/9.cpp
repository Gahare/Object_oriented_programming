#include <iostream>
#include <string>

using namespace std;

class publication
{
	string title;
	float price;
public:
	void getdata()
	{
		cout << "Enter title:"; cin >> title;
		cout << "Enter price:"; cin >> price;
	}
	void putdata() const
	{
		cout << "\nTitle: " << title;
		cout << "\nPrice: " << price;
	}
};

class publication2 : private  publication
{
	int day;
	int month;
	int year;
public:
	void setData()
	{
		publication::getdata();
		char sl;
		cout << "Enter title release date(12/12/1212):";
		cin >> day >> sl >> month >> sl >> year;
	}
	void getData() const
	{
		publication::putdata();
		cout << "\nTitle release date: " << day << "/" << month << "/" << year;
	}
};

class book : private publication2
{
	int pages;
public:
	void getdata()
	{
		publication2::setData();
		cout << "Enter number of pages:"; cin >> pages;
	}
	void putdata() const
	{
		publication2::getData();
		cout << "\nPages: " << pages;
	}
};

class tape : private publication2
{
	float time;
public:
	void getdata()
	{
		publication2::setData();
		cout << "Enter playing time:"; cin >> time;
	}
	void putdata() const
	{
		publication2::getData();
		cout << "\nPlaying time: " << time;
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