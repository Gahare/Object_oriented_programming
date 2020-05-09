#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <Windows.h>

using namespace std;

class bMoney {
	long double money;
	string str_o;
	string str = "$";
public:
  	bMoney() : money(0) {}
  	bMoney(long double num) : money(num) {}
	void ldtoms();
  	void set_money(string am) {
		money = stold(am);
  	}
  	void get_money() const {
		cout << str << endl;
  	}
  	operator long double () const {
		long double num = money;
		return num;
  	}
  	bMoney operator + (bMoney mon2) {
		return money + mon2.money;
	}
	bMoney operator - (bMoney mon2) {
		return money - mon2.money;
  	}
  	bMoney operator * (long double mon2) {
		return money * mon2;
	}
  	bMoney operator / (bMoney mon2) {
		return money / mon2.money;
  	}
  	bMoney operator / (long double mon2) {
		return money / mon2;
  	}
};

void bMoney::ldtoms() {
	str_o = to_string(money);
	for (int i = 0; i < 4; i++) {
		str_o.erase(str_o.length() - 1, 1);
  	}
  	int tail = str_o.find('.');
  	switch (tail % 3) {
  	  case 0:
	  	for (int i = 0, n = 3; i < tail; i++) {
			if (i == n) {
		  		n += 3;
		  		str.append(1, ' ');
		  		str.append(1, str_o.at(i));
			}
			else {
		  		str.append(1, str_o.at(i));
			}
	  	}
	  	break;
	  case 1:
	  	for (int i = 0, n = 1; i < tail; i++) {
			if (i == n) {
		  		n += 3;
		  		str.append(1, ' ');
		  		str.append(1, str_o.at(i));
			}
			else {
		  		str.append(1, str_o.at(i));
			}
	  	}
	  	break;
	  case 2:
	  	for (int i = 0, n = 2; i < tail; i++) {
			if (i == n) {
		 		n += 3;
		  		str.append(1, ' ');
		  		str.append(1, str_o.at(i));
			}
			else {
		  		str.append(1, str_o.at(i));
			}
	  	}
	  	break;
  	}

  str_o.erase(0, tail);
  str += str_o;
  tail = str.length();
  str[tail] = '\0';
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char ch;
	do {
		bMoney am1, am2, money;
		long double num;
		string mn1, mn2;
		cout << "\nEnter a transaction with monetary amounts to calculate them." << endl;
		cout << "First amount: "; getline(cin, mn1); am1.set_money(mn1);
		cout << "Second amount: "; getline(cin, mn2); am2.set_money(mn2);

		cout << "First amount + Second amount: ";
		money = am1 + am2; money.ldtoms(); money.get_money();
	  	cout << "First amount - Second amount: ";
	  	money = am1 - am2; money.ldtoms(); money.get_money();
	  	num = am2;
	  	cout << "First amount * Second amount (ld): ";
	  	money = am1 * num; money.ldtoms(); money.get_money();
	  	cout << "First amount / Second amount: ";
	  	money = am1 / am2; money.ldtoms(); money.get_money();
	  	cout << "First amount / Second amount (ld): ";
	  	money = am1 / num; money.ldtoms(); money.get_money();
		cout << "Would you like to continue (y/n)?.."; cin >> ch;
  	} while (ch != 'n');

  return 0;
}