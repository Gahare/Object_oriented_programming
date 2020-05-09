#include <iostream>
#include <string>

using namespace std;

class publication {
private:
	string title;
	float price;
public:
	virtual void getdata() {
		cout << "Enter title:";
		cin >> title;
		cout << "Enter price:";
		cin >> price;
	}
	virtual void putdata() {
		cout << "\nTitle: " << title;
		cout << "\nPrice: " << price;
	}
	virtual bool isOveersize() {
		return false;
	}
};

class book : public publication {
private:
	int pages;
public:
	void getdata() {
		publication::getdata();
		cout << "Enter number of pages:";
		cin >> pages;
	}
	void putdata() {
		publication::putdata();
		cout << "\nPages: " << pages;
	}
	bool isOveersize() {
		return pages > 800;
	}
};

class tape : public publication {
private:
	float time;
public:
	void getdata() {
		publication::getdata();
		cout << "Enter playing time:";
		cin >> time;
	}
	void putdata() {
		publication::putdata();
		cout << "\nPlaying time: " << time;
	}
	bool isOveersize() {
		return time > 90;
	}
};

int main() {
	publication *pubarr[100];
	int n = 0;
	char choice;

	do {
		cout << "Enter data for book or tape (b/t):";
		cin >> choice;
		if (choice == 'b') {
			pubarr[n] = new book;
		} else {
			pubarr[n] = new tape;
		}
		while (true) {
			pubarr[n]->getdata();
			if (pubarr[n]->isOveersize()) {
				cout << "Oversize!\n";
			} else {
				break;
			}
		}
		n++;
		cout << "Enter another (y/n)?";
		cin >> choice;
	} while (choice == 'y');

	for (int j = 0; j < n; j++) {
		pubarr[j]->putdata();
	}
	cout << endl;
	return 0;
}