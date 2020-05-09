#include <iostream>

using namespace std;

const int LIMIT = 100;

struct Pair
{
	int oX;
	int oY;

	Pair() : oX(0), oY(0) { }
	Pair(int x, int y)
	{
		oX = x; oY = y;
	}

};

class Stack
{
int arr[LIMIT];
int count;
public:
	Stack() : count(0) { }
	void push(int elements)
	{
		if(count == LIMIT)
		{
			cout << "Stack overflow!" << endl;
			exit(1);
		}
		arr[count++] = elements;
	}
	int pop()
	{
		if(count == 0)
		{
			cout << "Stack is empty!" << endl;
			exit(1);
		}
		return arr[--count];
	}
};

class pairStack : public Stack
{
public:
	pairStack() : Stack() {}
	void push(Pair elements)
	{
		Stack::push(elements.oX);
		Stack::push(elements.oY);
	}
	Pair pop()
	{
		int y = Stack::pop();
		int x = Stack::pop();
		return Pair(x, y);
	}
};

int main()
{
	pairStack s;
	Pair p;
	for(int i = 0; i < 5; i++)
	{
		p.oX = i * i + 10 * i;
		p.oY = i * i - 2 * i;
		s.push(p);
		cout << "A pair is placed on the stack: [" << p.oX << "; " << p.oY << "]" << endl;
	}

	for(int i = 0; i < 5; i++)
	{
		Pair newP = s.pop();
		cout << "Steam was received from the stack: [" << newP.oX << "; " << newP.oY << "]" << endl;
	}
}