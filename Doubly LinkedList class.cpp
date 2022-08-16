#include <iostream>
using namespace std;
class Node
{
	int data;
	Node* next;
	Node* previous;
public:
	void setData(int data)
	{
		this->data = data;
	}
	void setNext(Node* next)
	{
		this->next = next;
	}
	void setPrevious(Node* previous)
	{
		this->previous = previous;
	}
	int getData()
	{
		return data;
	}
	Node* getNext()
	{
		return next;
	}
	Node* getPrevious()
	{
		return previous;
	}
	Node(int data = 0, Node* next = NULL, Node* previous = NULL)
	{
		setData(data);
		setNext(next);
		setPrevious(previous);
	}
};
class LinkedList
{
	Node* head;
	Node* last;
	int length;
public:
	void setHead(Node* head)
	{
		this->head = head;
	}
	void setLast(Node* last)
	{
		this->last = last;
	}
	Node* getHead()
	{
		return head;
	}
	Node* getLast()
	{
		return last;
	}
	int getLength()
	{
		return length;
	}
	LinkedList(Node* head = NULL, Node* last = NULL)
	{
		setHead(head);
		setLast(last);
		length = 0;
	}
	bool isEmpty()
	{
		return (head == NULL);
	}
	void insetAtBeginning(int val)
	{
		Node* temp = new Node(val);
		if (isEmpty())
		{
			head = temp;
			last = temp;
			length++;
		}
		else
		{
			head->setPrevious(temp);
			temp->setNext(head);
			head = temp;
			length++;
		}
	}
	void insertAtLast(int val)
	{
		Node* temp = new Node(val);
		if (isEmpty())
		{
			head = temp;
			last = temp;
			length++;
		}
		else
		{
			temp->setPrevious(last);
			last->setNext(temp);
			last = temp;
			length++;
		}
	}
	bool removeFromBeginning()
	{
		if (isEmpty())
		{
			return false;
		}
		else
		{
			if (length == 1)
			{
				delete head;
				head = last = NULL;
				length--;
				return true;
			}
			Node* temp = head->getNext();
			temp->setPrevious(NULL);
			delete head;
			head = temp;
			length--;
			return true;
		}
	}
	bool removeFromLast()
	{
		if (isEmpty())
			return false;

		if (length == 1)
		{
			delete head;
			head = last = NULL;
			length--;
			return true;
		}

		Node* temp = last->getPrevious();
		temp->setNext(NULL);
		delete last;
		last = temp;
		length--;
		return true;
	}
	void print()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->getData() << "-->";
			temp = temp->getNext();
		}
		cout << "NULL\n";
	}
	void printReverse()
	{
		Node* temp = last;
		cout << "NULL";
		while (temp != NULL)
		{
			cout << "<--" << temp->getData();
			temp = temp->getPrevious();
		}
	}
	int getFirstElement()
	{
		return head->getData();
	}
	int getLastElement()
	{
		return last->getData();
	}
	int getNthElement(int index)
	{
		if (index == 1)
			return head->getData();

		if (index == length)
			return last->getData();

		if (index > 0 && index <= length)
		{
			Node* temp = head;
			for (int i = 1; i <= index-1; i++)
				temp = temp->getNext();

			return temp->getData();
		}

		cout << "\nindex is out of range";
		return -9999;
	}

};
int main()
{
	LinkedList l1;
	l1.insetAtBeginning(10);
	l1.insertAtLast(99);
	l1.print();
	l1.printReverse();
	l1.removeFromLast();
	l1.removeFromBeginning();
	if (l1.isEmpty())
		cout << "\nempty\n";

	l1.insertAtLast(1000);
	l1.insetAtBeginning(1200);
	l1.insertAtLast(1010);

	l1.print();

	cout << "mid value is " << l1.getNthElement(3);

	cout << "\n length is " << l1.getLength();





   return 0;
}
