#include <iostream>
using namespace std;

class sterling {
protected:
	int pounds;
	int shillings;
	int pense;
	char point;
public:
	sterling() : pounds(0), shillings(0), pense(0), point('.') {}
	sterling(int pou, int s, int pe) : pounds(pou), shillings(s), pense(pe) {
		point = '.';
	}
	sterling(double decpounds) {
		pounds = static_cast<int>(decpounds);
		float decfrac = (decpounds - pounds) * 20;
		shillings = static_cast<int>(decfrac);
		decfrac = (decfrac - shillings) * 12;
		pense = static_cast<int>(decfrac);
		point = '.';
	}
	operator double() const {
		double decpounds = (double)(pounds * 240 + shillings * 12 + pense) / 240;
		return decpounds;
	}
	void get() {
		cout << "Enter the amount int the old currency units:";
		cin >> pounds >> point >> shillings >> point >> pense;
	}
	void put() {
		cout << 'F' << pounds << point << shillings << point << pense;
	}
};

class sterfrac : public sterling {
	int eights;
public:
	sterfrac() : sterling() {}
	sterfrac(int Pounds, int Shilling, int Pence, int Eights = 0) : eights(Eights) {
		sterling(Pounds, Shilling, Pence);
	}
	sterfrac(double NewPounds) : sterling(NewPounds) {
		NewPounds = (NewPounds - (long)NewPounds) * 20;
		NewPounds = (NewPounds - (int)NewPounds) * 12;
		eights = (NewPounds - (int)NewPounds) * 8;
	}

	sterfrac operator+(sterfrac s) {
		return sterfrac(operator double() + double(s));
	}
	sterfrac operator-(sterfrac s) {
		return sterfrac(operator double() - double(s));
	}
	sterfrac operator*(double s) {
		return sterfrac(operator double() * s);
	}
	sterfrac operator/(sterfrac s) {
		return sterfrac(operator double() / double(s));
	}
	sterfrac operator/(double s) {
		return sterfrac(operator double() / s);
	}
	operator double() {
		return sterling::operator double() + eights / 8.0 / 240.0;
	}

	void get() {
		char ch;
		int a, b;
		sterling::get();
		cin >> ch >> a >> ch >> b;
		eights = a * 8 / b;
	}
	void put() {
		sterling::put();
		int tnum, tden, temp;
		tnum = eights;
		tden = 8;
		while (tnum != 0) {
			if (tnum < tden) {
				temp = tnum;
				tnum = tden;
				tden = temp;
			}
			tnum -= tden;
		}
		if (eights / tden != 0) {
			cout << '-' << eights / tden << '/' << 8 / tden;
		}
		cout << endl;
	}

};

int main() {
	sterfrac sf, sf1;
	sf.get();
	sf1.get();

	sterfrac sf2 = sf + sf1;
	cout << "sf + sf1 = ";
	sf2.put();

	sf2 = sf - sf1;
	cout << "sf - sf1 = ";
	sf2.put();

	sf2 = sf / sf1;
	cout << "sf / sf1 = ";
	sf2.put();

	cout << "Enter the number by which you should multiply the amount:";
	double number;
	cin >> number;

	sf2 = sf * number;
	cout << "sf * " << number << " = ";
	sf2.put();
	sf2 = sf1 * number;
	cout << "sf1 * " << number << " = ";
	sf2.put();

	sf2 = sf / number;
	cout << "sf / " << number << " = ";
	sf2.put();
	sf2 = sf1 / number;
	cout << "sf1 / " << number << " = ";
	sf2.put();

	return 0;
}