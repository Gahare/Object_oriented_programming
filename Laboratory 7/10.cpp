#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Polar {
	double corner;
	double radius;
	double X;
	double Y;
public:
	Polar () : corner(0), radius (0), X(0), Y(0) {}
	Polar (double x, double y) : X(x), Y(y) {}

	void setPolar () {
		cout << "Enter corner:"; cin >> corner;

		if (corner < 0 || corner > 360) {
			exit(1);
		}

		cout << "Enter radius:"; cin >> radius;

		X = radius * cos(corner);
		Y = radius * sin(corner);
	}
	void display() {
		corner = tan(Y/X); radius = hypot(X, Y);
		cout << "Result of adding polar coordinates." << endl << "Corner: " << corner << endl << "Radius: " << radius
		<< endl;
	}
	Polar operator + (Polar pol) {
		double tempX = X + pol.X;
		double tempY = Y + pol.Y;
		return Polar(tempX, tempY);
	}
};

int main() {
	Polar firstPolarCoordinates, secondPolarCoordinates, sumOfPolarCoordinates;

	cout << "Enter the polar coordinates to add them." << endl;
	firstPolarCoordinates.setPolar(); secondPolarCoordinates.setPolar();

	sumOfPolarCoordinates = firstPolarCoordinates + secondPolarCoordinates;
	sumOfPolarCoordinates.display();

	return 0;
}