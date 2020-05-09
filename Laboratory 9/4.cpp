#include <iostream>

using namespace std;

struct link
{
	int data;
	link* next;
};

class linklist
{
private:
	link* first;
public:
	linklist()
	{
		first = NULL;
	}
	~linklist();
	void additem(int d);
	void display();
};

void linklist::additem(int d)
{
	link* newlink = new link;          //make a new link
	newlink -> data = d;                 //give it data
	newlink -> next = first;             //it points to next link
	first = newlink;                   //now first points to this
}

void linklist::display()
{
	link* current = first;             //set ptr to first link
	while( current != NULL )           //quit on last link
	{
		cout << endl << current->data;  //print data
		current = current->next;        //move to next link
	}
}

linklist::~linklist()
{
	link* current = first;             //set ptr to first link
	while( current != NULL )           //quit on last link
	{
		link* temp = current;           //save ptr to this link
		current = current->next;        //get ptr to next link
		delete temp;                    //delete this link
	}
}

int main()
{
	linklist li;

	li.additem(25);    //add four items to list
	li.additem(36);
	li.additem(49);
	li.additem(64);

	li.display();      //display entire list
	cout << endl;
	return 0;
}
