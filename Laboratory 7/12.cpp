#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class bMoney;

class Sterling {
	long pounds;
	int shilling;
	int pens;
public:
	Sterling () : pounds(0), shilling(0), pens(0) {}
	Sterling (long po, int s, int pe) : pounds(po), shilling(s), pens(pe) {}
	void getSterling() {
		char point;
		cin >> pounds >> point >> shilling >> point >> pens;
	}
	Sterling (bMoney money);
	void putSterling() const {
		cout << pounds << "." << shilling << "." << pens << endl;
	}
	operator double () {
		float sum = pens + shilling * 12 + (pounds * 20) * 12;
		double des_funt = (sum / 2.4) / 100;
		return des_funt;
	}
	long get_pounds() {
		return pounds;
	}
	int get_shilling() {
		return shilling;
	}
	int get_pens() {
		return pens;
	}
};

class bMoney {
	long double money;
	string str_o;
	string str = "$";
public:
	bMoney() : money(0) {}
	bMoney (Sterling strl);
	bMoney(long double num) : money(num) {}
	void ldtoms();
	void set_money(string am) {
		money = stold(am);
	}
	void print_money() const {
		cout << str << endl;
	}
	operator long double () const {
		long double num = money;
		return num;
	}
	long double get_money() {
		return money;
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

bMoney::bMoney(Sterling strl) {
	long po = strl.get_pounds();
	int s = strl.get_shilling();
	int pe = strl.get_pens();
	money = (po * 50) + ((50 / 20) * s) + ((50 * 20 * 12) * pe);
}

Sterling::Sterling(bMoney money) {
	long double dollar = money.get_money();
	int sumpens = (dollar / 50) * 240;
	pounds = sumpens / 240;
	shilling = (sumpens % 240) / 12;
	pens = (sumpens % 240) % 12;
}

int main() {
	Sterling initialPounds, equivalentValueInPounds;
	bMoney initialDollars, equivalentValueInDollars;
	string strValue;

	cout << "Enter the amount of money in dollars:$";
	getline(cin, strValue); initialDollars.set_money(strValue);
	equivalentValueInPounds = initialDollars;
	cout << "Equivalent in pounds: "; equivalentValueInPounds.putSterling();

	cout << "Enter the amount of money in pounds (1.2.3):"; initialPounds.getSterling();
	equivalentValueInDollars = initialPounds; equivalentValueInDollars.ldtoms();
	cout << "Equivalent in dollars: "; equivalentValueInDollars.print_money();
}