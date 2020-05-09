#include <iostream>
#include <string>

using namespace std;

class person
{
protected:
	string name;
	float salary;
public:
	void setData()
	{
		cout << "Enter name:"; cin >> name;
		cout << "Enter salary:"; cin >> salary;
	}
	void printData()
	{
		cout << endl << name << " $" << salary;
	}
	string getName()
	{
		return name;
	}
	float getSalary()
	{
		return salary;
	}
};

void salsort(person **p_person, int n)
{
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if((*(p_person + j))->getSalary() > (*(p_person + j + 1))->getSalary()) {
				person* temp = *(p_person + j);
				*(p_person + j) = *(p_person + j + 1);
				*(p_person + j + 1) = temp;
			}
		}
	}
}

int main()
{
	person* persPtr[100];
	int n = 0;
	char choice;

	do {
		persPtr[n] = new person;
		persPtr[n]->setData();
		n++;
		cout << "Enter another (y/n)?..";
		cin >> choice;
	} while( choice == 'y');

	cout << "\nUnsorted list:";
	for(int j = 0; j < n; j++) {
		persPtr[j]->printData();
	}

	salsort(persPtr, n);

	cout << "\nSorted list:";
	for(int j = 0; j < n; j++) {
		persPtr[j]->printData();
	}

	cout << endl;
	return 0;
}
