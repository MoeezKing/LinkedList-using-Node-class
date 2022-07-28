#include <iostream>
using namespace std;
class Node
{
	int data;
	Node* next;
public:
	void setData(int data)
	{
		this->data = data;
	}
	void setNext(Node* next)
	{
		this->next = next;
	}
	int getData()
	{
		return data;
	}
	Node* getNext()
	{
		return next;
	}
	Node(int data = 0, Node* next = NULL)
	{
		setData(data);
		setNext(next);
	}

};
class LinkedList
{
	Node* head;
public:
	void setHead(Node* head)
	{
		this->head = head;
	}
	Node* getHead()
	{
		return head;
	}
	LinkedList(Node* head = NULL)
	{
		setHead(head);
	}
	bool isEmpty()
	{
		return (head == NULL) ? true :  false;
	}
	void insertAtBeginning(int data)
	{
		if (isEmpty())
		{
			Node* t = new Node(data);
			head=t;
		}
		else
		{
			Node* t = new Node(data);
			t->setNext(head);
			head = t;
		}
	}
	void insertAtLast(int data)
	{
		if (isEmpty())
		{
			Node* t = new Node(data);
			head = t;
		}
		else
		{
			Node* t = new Node(data);
			Node* last = head;
			while (last->getNext() != NULL)
			{
				last = last->getNext();
			}
			last->setNext(t);
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
			Node* t = head->getNext();
			delete head;
			head = t;
			return true;
		}
	}
	int getLenght()
	{
		int lenght = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			lenght++;
			temp = temp->getNext();
		}
		return lenght;
	}
	bool removeFromLast()
	{
		if (isEmpty())
		{
			return false;
		}
		else
		{
			int lenght = getLenght();
			Node* temp = head;
			while (temp->getNext() != NULL)
			{
				temp = temp->getNext();
			}
			delete temp;
			temp = head;
			for (int i = 0; i < lenght-2; i++)
			{
				temp = temp->getNext();
			}
			temp->setNext(NULL);
			return true;
		}
	}
	int getFirstElement()
	{
		return head->getData();
	}
	int getLastElement()
	{
		Node* last = head;
		while (last->getNext() != NULL)
		{
			last = last->getNext();
		}
		return last->getData();
	}
	void print()
	{
		cout << endl;
		Node* temp=head;
		while (temp != NULL)
		{
			cout << temp->getData() << endl;
			temp = temp->getNext();
		}
	}
	int getNthElement(int n)//To get nth term
	{
		int lenght = getLenght();
		if (n <= lenght)
		{
			if (n == 1)
			{
				return head->getData();
			}
			else
			{
				Node* temp = head;
				for (int i = 0; i < n-1; i++)
				{
					temp = temp->getNext();
				}
				return temp->getData();
			}
		}
		else
		{
			cout << n << " term is out of range of size of this Linked List.";
			return NULL;
		}

	}
};
int main()
{
	LinkedList l1;
	
	l1.insertAtBeginning(1);
	l1.insertAtLast(2);
	cout << "Lenght of LinkedList is " << l1.getLenght();
	l1.print();

	cout << "\nFirst element is " << l1.getFirstElement();
	cout << "\nLast element is " << l1.getLastElement();

	l1.removeFromBeginning();
	cout << "\nAfter deleting from beginning ";
	l1.print();

	l1.insertAtBeginning(10);
	l1.removeFromLast();
	cout << "\nAfter deleting from last as first elemnet inserted in list was 10 at beginning";
	l1.print();

	cout << "\nNow, lenght of list is " << l1.getLenght();

	
	for (int i = 0; i < 20; i++)
	{
		l1.insertAtLast(i+1);
		l1.insertAtBeginning(i);
	}
	cout << "\nLenght is " << l1.getLenght();
	l1.print();

	cout << endl;
	l1.removeFromBeginning();
	l1.removeFromLast();
	cout << "\nAfter one element from last and beginning .";
	cout << "\nLenght is " << l1.getLenght();
	l1.print();

	cout << "\nFirst element in list is " << l1.getFirstElement();
	cout << "\nLast element in list is " << l1.getLastElement();
	
	cout << endl;
	int nth = l1.getNthElement(3);
		if (nth != NULL)
	{
		cout << "3rd term is " << nth;
	}
		
		cout << endl;
		nth = l1.getNthElement(45);
		if (nth != NULL)
		{
			cout << "45th term is " << nth;
		}
	return 0;
}
