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

class Pstring2 : public String
{
public:
	void Left(int symbols)
	{
		for(int i = 0 ; i < symbols ; i++ )
		{
			for(int j = 0; j < strlen(str); j++)
			{
				str[j] = str[j+1];
			}
		}
	}
	void Right(int symbols)
	{
		for(int i = 0; i < symbols ; i++ )
		{
			str[strlen(str) - 1] = '\0';
		}
	}
	void Mid(int symbols, int index)
	{
		int len = strlen(str);
		for(int i = index; len - strlen(str) != symbols; )
		{
			int j = i;
			while(j < strlen(str)) {
				str[j] = str[j + 1];
				j++;
			}
		}
	}
};

class Pstring : public Pstring2
{
public:
	Pstring(const char s[])
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
};

int main()
{
	Pstring s1 = "This is a very long string which is probably";
	cout << "\ns1: "; s1.display();

	s1.Left(2);
	cout << "\ns1 (-2 LEFT): "; s1.display();

	s1.Right(2);
	cout << "\ns1 (-2 RIGHT): "; s1.display();

	s1.Mid(3,2);
	cout << "\ns1 (-3 from 2 index): "; s1.display();

	return 0;
}
