#include <iostream>

using namespace std;

int compstr(const char* s1, const char* s2)
{
	for(int i = 0; i < sizeof(s1); i++) {
		if (*(s1 + i) == *(s2 + i)) {
			continue;
		}
		return *(s1 + i) > *(s2 + i) ? 1 : -1;
	}
	return 0;
}

int main()
{
	char str1[] = "first line";
	char str2[] = "second line";

	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;

	cout << "compstr(str1, str2): " << compstr(str1, str2) << endl;
	cout << "compstr(str2, str2): " << compstr(str2, str2) << endl;
	cout << "compstr(str2, str1): " << compstr(str2, str1) << endl;

}