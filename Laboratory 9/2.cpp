#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class String
{
private:
	char* str;
public:
	String(char* s)
	{
		int length = strlen(s);
		str = new char[length+1];
		strcpy(str, s);
	}
	~String()
	{
		delete str;
	}
	void display()
	{
		cout << str;
	}
	void upit();
};

void String::upit()
{
	char* ptrch = str;
	while( *ptrch )
	{
		*ptrch = toupper(*ptrch);
		ptrch++;
	}
}

int main()
{
	String s1 = "He who laughs last laughs best.";

	cout << "\ns1=";
	s1.display();
	s1.upit();
	cout << "\ns1=";
	s1.display();
	cout << endl;
	return 0;
}
