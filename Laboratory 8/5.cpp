#include <iostream>

using namespace std;

const int LEN = 80;

class employee
{
	char name[LEN];
	unsigned long number;
public:
	void setData()
	{
		cout << "Enter last name:"; cin >> name;
		cout << "Enter number:"; cin >> number;
	}
	void getData() const
	{
		cout << "\nName: " << name;
		cout << "\nNumber: " << number;
	}
};

class employee2 : public employee
{
	double compensation;
	enum etype {hourly, weekly, monthly};
	etype period;
public:
	void setData()
	{
		employee::setData();
		char type;
		cout << "Enter compensation:"; cin >> compensation;
		cout << "Enter the payment period (h - hourly, w - weekly, m - monthly):"; cin >> type;
		switch(type)
		{
			case 'h' : period = hourly; break;
			case 'w' : period = weekly; break;
			case 'm' : period = monthly; break;
		}
	}
	void getData() const
	{
		employee::getData();
		cout << "\nEmployee compensation: " << compensation;
		cout << "\nPayment period: ";
		switch (period)
		{
			case hourly : cout << "hourly"; break;
			case weekly : cout << "weekly"; break;
			case monthly : cout << "monthly"; break;
		}
	}
};

int main()
{
	employee2 emp;
	
	emp.setData();
	emp.getData();
}