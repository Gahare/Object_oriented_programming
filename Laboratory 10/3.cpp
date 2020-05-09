#include <iostream>

using namespace std;

class Distance {
private:
	int feet;
	float inches;
public:
	Distance() {
		feet = 0;
		inches = 0.0;
	}
	Distance(float fltfeet) {
		feet = static_cast<int>(fltfeet);
		inches = 12 * (fltfeet - feet);
	}
	Distance(int ft, float in) : feet(ft), inches(in) {}
	void showdist() {
		cout << feet << "\'-" << inches << '\"';
	}
	friend Distance operator*(Distance, Distance);
};
Distance operator*(Distance d1, Distance d2) {
	float fltfeet1 = d1.feet + d1.inches / 12;
	float fltfeet2 = d2.feet + d2.inches / 12;
	float multfeet = fltfeet1 * fltfeet2;
	return Distance(multfeet);
}

int main() {
	Distance dist1(3, 6.0);
	Distance dist2(2, 3.0);
	Distance dist3;

	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();


	dist3 = dist1 * dist2;
	cout << "\ndist1 * dist2 = "; dist3.showdist();
	dist3 = 10.0 * dist3;
	cout << "\n10.0 * (dist1 * dist2) = "; dist3.showdist();

	cout << endl;
	return 0;
}
