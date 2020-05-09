#include <iostream>
#include <cmath>
#include <conio.h>

const char ESC = 27;

using namespace std;

class fraction {
	int numerator, denominator;
 public:
	fraction():numerator(0), denominator(0) {}
	fraction (int n, int d) : numerator(n), denominator(d) {}

	void set_fraction() {
		char ch;
		cin >> numerator >> ch >> denominator;
		if ((numerator == 0 && denominator == 0) || (numerator == 1 && denominator == 1) ||
		(numerator == 0 && denominator == 1)) {
		  	cout << "Error!" << endl;
		  	exit (1);
		}
  	}

  	fraction operator + (fraction f2) {
		int n = numerator * f2.denominator + denominator * f2.numerator;
		int d = denominator * f2.denominator;
		return fraction(n, d);
  	}
  	fraction operator - (fraction f2) {
		int n = numerator * f2.denominator - denominator * f2.numerator;
		int d = denominator * f2.denominator;
		return fraction(n, d);
  	}
  	fraction operator * (fraction f2) {
		int n = numerator * f2.numerator;
		int d = denominator * f2.denominator;
		return fraction(n, d);
  	}
  	fraction operator / (fraction f2) {
		int n = numerator * f2.denominator;
		int d = denominator * f2.numerator;
		return fraction(n, d);
  	}

  	void lowterms() {
		long tnum, tden, temp, gcd;
		tnum = labs(numerator);
		tden = labs(denominator);
		if (tden == 0) {
			cout << "Invalid denominator!"; exit(1);
		} else if (tnum == 0) {
	  		numerator = 0; denominator = 1; return;
		}
		while (tnum != 0) {
	  		if (tnum < tden) {
				temp = tnum; tnum = tden; tden = temp;
	  		}
	  		tnum = tnum - tden;
		}
		gcd = tden;
		numerator = numerator / gcd;
		denominator = denominator / gcd;
	}

  	void print_fraction()const {
	  cout << "Result: " << numerator << "/" << denominator << endl;
	}
};

int main() {
  	setlocale(0, "");

	char ch;
	do {
		fraction fr1, fr2, fr_sum;
		cout << "Enter action with fraction (1/2+1/3): ";
		fr1.set_fraction(); cin >> ch; fr2.set_fraction();

		switch (ch) {
	  		case '+': fr_sum = fr1 + fr2; break;
	  		case '-': fr_sum = fr1 - fr2; break;
	  		case '*': fr_sum = fr1 * fr2; break;
	  		case '/': fr_sum = fr1 / fr2; break;
		}
		fr_sum.lowterms();
		fr_sum.print_fraction();
		cout << "Would you like to continue (ESC to exit)?.. ";
		ch = _getche(); cout << endl;
  	}
	while (ch != ESC);
	return 0;
}