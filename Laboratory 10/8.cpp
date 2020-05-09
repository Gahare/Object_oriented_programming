#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int LIMIT = 100;
const int MAX = 100;

class Token {
public:
	virtual float getNumber() = 0;
	virtual char getOperand() = 0;
};

class Operand : public Token {
	char oper;
public:
	Operand(char oper) : oper(oper) {}
	char getOperand() {
		return oper;
	}
	float getNumber() {
		return 0;
	}
};

class Number : public Token {
	float fNumber;
public:
	Number(float fnum) : fNumber(fnum) {}
	float getNumber() {
		return fNumber;
	}
	char getOperand() {
		return 0;
	}
};

class Stack {
	Token *arr[LIMIT];
	int next;
public:
	Stack() : next(0) {}
	void push(Token *el) {
		if (next == LIMIT) {
			cout << "\nStack overflow\n";
			return;
		}
		arr[next++] = el;
	}
	Token *pop() {
		if (next == 0) {
			cout << "\nStack is empty\n";
			exit(0);
		}
		return arr[--next];
	}
	int count() {
		return next;
	}
};

class express {
	Stack s;
	char *pStr;
	int len;
public:
	express(char *ptr) {
		pStr = ptr;
		len = strlen(pStr);
	}
	float operation(float f1, float f2, char op) {
		switch (op) {
			case '+': return f1 + f2;
				break;
			case '-': return f1 - f2;
				break;
			case '*': return f1 * f2;
				break;
			case '/': return f1 / f2;
				break;
			default: cout << "\nНеизвестный оператор" << op;
				exit(1);
		}
	}
	bool isOperand(char ch) {
		return ch == '+' || ch == '-' || ch == '*' || ch == '/';
	}
	void parse() {
		char lastop, temp[MAX];
		float lastval, secval, buf;
		int k, j;
		for (j = 0, k = 0; j < len; j++) {
			if (isdigit(pStr[j]) || pStr[j] == '.') {
				temp[k++] = pStr[j];
			} else {
				temp[k] = '\0';
				k = 0;
				buf = stof(temp);
				s.push(new Number(buf));

				if (!isOperand(pStr[j])) {
					cout << "\nНеизвестный символ";
					exit(1);
				}
				if (s.count() == 1)
					s.push(new Operand(pStr[j]));
				else {
					lastval = s.pop()->getNumber();
					lastop = s.pop()->getOperand();
					if ((pStr[j] == '*' || pStr[j] == '/') && (lastop == '+' || lastop == '-')) {
						s.push(new Operand(lastop));
						s.push(new Number(lastval));
					} else {
						secval = s.pop()->getNumber();
						s.push(new Number(operation(secval, lastval, lastop)));
					}
					s.push(new Operand(pStr[j]));
				}
			}
		}
		temp[k] = '\0';
		buf = stof(temp);
		s.push(new Number(buf));
	}
	float solve() {
		float lastval, secval;
		char oper, oper2;
		while (s.count() > 2) {
			lastval = s.pop()->getNumber();
			oper = s.pop()->getOperand();
			secval = s.pop()->getNumber();
			if (s.count() != 0) {
				oper2 = s.pop()->getOperand();
				if (oper2 == '-') {
					secval *= -1;
					oper2 = '+';
				}
				s.push(new Operand(oper2));
			}
			s.push(new Number(operation(secval, lastval, oper)));
		}
		return s.pop()->getNumber();
	}
};

int main() {
	char ch;
	char expression[MAX];
	cout << "Enter the arithmetic expression as 2+3*4/3-2";
	do {
		cout << "\nEnter the expression:";
		cin >> expression;
		express *eptr = new express(expression);
		eptr->parse();
		cout << "Result: " << eptr->solve();
		delete eptr;
		cout << "\nWould you like to continue typing (y/n)?..";
		cin >> ch;
	} while (ch == 'y');
	return 0;
}
