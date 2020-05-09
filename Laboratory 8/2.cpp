#include <iostream>
#include <cstring>

using namespace std;

class String
{
protected:
	enum { SZ = 80 };
	char str[SZ];
public:
	String() {
		str[0] = '\0';
	}
	String(const char s[]) {
		strcpy(str, s);
	}
	void display() const {
		cout << str;
	}
	operator char*() {
		return str;
	}
};

class Pstring : public String
{
public:
	Pstring(const char s[]);
};

Pstring::Pstring(const char s[])
{
	int i;
	if(strlen(s) > SZ - 1) {
		for( i = 0; i < SZ - 1; i++) {
			str[i] = s[i];
		}
		str[i] = '\0';
	}
	else {
		strcpy(str, s);
	}
}

int main()
{
	Pstring s1 = "This is a very long string which is probably"
				 "no, certainly--going to exceed the limit set by SZ.";
	cout << "\ns1="; s1.display();

	Pstring s2 = "This is a short string.";
	cout << "\ns2="; s2.display();
	cout << endl;
	return 0;
}