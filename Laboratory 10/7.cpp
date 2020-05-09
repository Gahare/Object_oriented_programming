#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

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
	operator long double() const {
		long double num = money;
		return num;
	}
	bMoney operator+(bMoney mon2) {
		return money + mon2.money;
	}
	bMoney operator-(bMoney mon2) {
		return money - mon2.money;
	}
	bMoney operator*(long double mon2) {
		return money * mon2;
	}
	bMoney operator/(bMoney mon2) {
		return money / mon2.money;
	}
	bMoney operator/(long double mon2) {
		return money / mon2;
	}
	friend bMoney round(bMoney mon) {
		long double temp = mon.money;
		if (modfl(mon.money, &temp) >= 0.55) {
			temp += 1;
		}
		return bMoney(temp);
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
				} else {
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
				} else {
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
				} else {
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
	bMoney am, money;
	string mn;
	char ch;
	do {
		cout << "Enter the amount in dollars:"; cin >> mn;
		am.set_money(mn); money = round(am); money.ldtoms();
		cout << "The amount of money is equal to: "; money.get_money();
		cout << "Would you like to continue (y/n)?..";
		cin >> ch;
	} while (ch == 'y');
	return 0;
}