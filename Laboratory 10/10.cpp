#include <iostream>

using namespace std;

struct link {
	int data;
	link *next;
};

class linklist {
	link *first;
public:
	linklist() {
		first = NULL;
	}
	linklist(const linklist &list) {
		if (list.first == NULL) return;
		first = new link();
		first->data = list.first->data;
		link *cur1 = first;
		link *cur2 = list.first;
		while (cur2->next != NULL) {
			cur2 = cur2->next;
			cur1->next = new link();
			cur1 = cur1->next;
			cur1->data = cur2->data;
		}
	}
	linklist &operator=(const linklist &list) {
		*this = linklist(list);
		return *this;
	}

	~linklist();
	void additem(int d);
	void display();
};

void linklist::additem(int d) {
	link *newlink = new link;
	newlink->data = d;
	newlink->next = first;
	first = newlink;
}

void linklist::display() {
	link *current = first;
	while (current != NULL) {
		cout << " " << current->data;
		current = current->next;
	}
}

linklist::~linklist() {
	link *current = first;
	cout << "\nDelete the list: ";
	while (current != NULL) {
		link *temp = current;
		current = current->next;
		cout << temp->data << " ";
		delete temp;
	}
}

int main() {
	linklist *li = new linklist();
	cout << "New Listing Announcement:";
	li->additem(1);
	li->additem(2);
	li->additem(3);
	li->additem(4);
	li->display();
	linklist copy = *li;
	delete li;
	cout << "\nChecking a copy of the list:";
	copy.display();
	cout << endl;
	return 0;
}
