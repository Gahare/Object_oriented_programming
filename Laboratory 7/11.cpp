#include <iostream>

using namespace std;

class Sterling {
	long pounds;
	int shilling;
	int pens;
public:
	Sterling () : pounds(0), shilling(0), pens(0) {}
	Sterling (double funt) {
		pounds = static_cast<long> (funt);
		long deschast = funt - pounds;
		shilling = static_cast<int> (deschast*20);
		pens = static_cast<int> ((funt - pounds) * 240 - shilling * 12);
	}
	Sterling (long po, int s, int pe) : pounds(po), shilling(s), pens(pe) {}
	void getSterling() {
		char point;
		cout << "Enter the money in the old format(1.2.3):";
		cin >> pounds >> point >> shilling >> point >> pens;
	}
	void putSterling() const {
		cout << pounds << "." << shilling << "." << pens << endl;
	}
	Sterling operator + (Sterling str2) {
		int sumpens = (pounds * 240 + shilling * 12 + pens) + (str2.pounds * 240 + str2.shilling * 12 + str2.pens);
		long po = sumpens / 240;
		int s = (sumpens % 240) / 12;
		int pe = (sumpens % 240) % 12;
		return Sterling(po, s, pe);
	}
	Sterling operator - (Sterling str2) {
		int sumpens = (pounds * 20 * 12 + shilling * 12 + pens) - (str2.pounds * 20 * 12 + str2.shilling * 12 +
			str2.pens);
		long po = sumpens / (20 * 12);
		int s = sumpens % (20 * 12) / 12;
		int pe = sumpens % (20 * 12) % 12;
		return Sterling(po, s, pe);
	}
	Sterling operator * (double str2) {
		int sumPens = (pounds * 20 * 12 + shilling * 12 + pens) * (str2);
		long po = sumPens / (20 * 12);
		int s = sumPens % (20 * 12) / 12;
		int pe = sumPens % (20 * 12) % 12;
		return Sterling(po, s, pe);
	}
	Sterling operator / (Sterling str2) {
		int sumpens = (pounds * 20 * 12 + shilling *12 + pens) / (str2.pounds * 20 * 12 + str2.shilling * 12 +
			str2.pens);
		long po = sumpens / (20 * 12);
		int s = sumpens % (20 * 12) / 12;
		int pe = sumpens % (20 * 12) % 12;
		return Sterling(po, s, pe);
	}
	Sterling operator / (double str2) {
		int sumpens = (pounds * 20 * 12 + shilling * 12 + pens) / (str2);
		long po = sumpens / (20 * 12);
		int s = sumpens % (20 * 12) / 12;
		int pe = sumpens % (20 * 12) % 12;
		return Sterling(po, s, pe);
	}
	operator double () {
		float sum = pens + shilling * 12 + (pounds * 20) * 12;
		double des_funt = (sum / 2.4) / 100;
		return des_funt;
	}
};

int main() {
	Sterling firstPoundCashInOldFormat, secondPoundCashInOldFormat, sum;
	double decimalFormatPound;

	firstPoundCashInOldFormat.getSterling(); secondPoundCashInOldFormat.getSterling();
	cout << "First money + Second money = ";
	sum = firstPoundCashInOldFormat+secondPoundCashInOldFormat; sum.putSterling();
	cout << "First money - Second money = ";
	sum = firstPoundCashInOldFormat-secondPoundCashInOldFormat; sum.putSterling();
	cout << "First money / Second money = ";
	sum = firstPoundCashInOldFormat/secondPoundCashInOldFormat; sum.putSterling();
	cout << "Enter decimal pounds:" ; cin >> decimalFormatPound;
	cout << "First money * Second money (decimal format) = ";
	sum = firstPoundCashInOldFormat*decimalFormatPound; sum.putSterling();
	cout << "First money / Second money (decimal format) = ";
	sum = firstPoundCashInOldFormat/decimalFormatPound; sum.putSterling();
	decimalFormatPound = sum;
	cout << "First money / Second money (decimal format) = " << decimalFormatPound;
}