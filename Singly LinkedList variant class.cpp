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
    Node* last;
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
    LinkedList(Node* head = NULL, Node* last = NULL)
    {
        setHead(head);
        setLast(last);
    }
    bool isEmpty()
    {
        if (head == NULL && last == NULL)
            return true;
        else
            return false;
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
    void insertFromBeginning(int val)
    {
        Node* temp = new Node(val);
        temp->setNext(head);
        head = temp;
        if (last == NULL)
            last = temp;
    }
    void insertFromLast(int val)
    {
        Node* temp = new Node(val);
        if (isEmpty())
        {
            head = temp;
            last = temp;
        }
        else
        {
            last->setNext(temp);
            last = temp;
        }
    }
    bool removeFromBeginning()
    {
        if (isEmpty())
            return false;
        else
        {
            int lenght = getLenght();
            Node* temp = head->getNext();
            if (lenght != 1)
            {
                delete head;
                head = temp;
                return true;
            }
            else
            {
                delete head;
                head = temp;
                last = head;
                return true;
            }
        }
    }
    bool removeFromLast()
    {
        if(isEmpty())
            return false;
        
        int lenght = getLenght();
        if (lenght == 1)
        {
            delete head;
            head = NULL;
            last = NULL;
            return true;
        }
        
        delete last;
        Node* temp = head;
        for (int i = 1; i < lenght-1; i++)
            temp = temp->getNext();
        temp->setNext(NULL);
        last = temp;
        return true;
    }
    int getFirstElement()
    {
        if (isEmpty())
            return NULL;
        else
            return head->getData();
    }
    int getLastElement()
    {
        if (isEmpty())
            return NULL;
        else
            return last->getData();
    }
    void print()
    {
        cout << endl;
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->getData() << endl;
            temp = temp->getNext();
        }
    }
};
int main()
{
    LinkedList l1;
    if (l1.isEmpty())
        cout << endl << "empty";
    else
        cout << endl << "not empty";
    for (int i = 0; i < 20; i++)  
    {
        l1.insertFromLast(i + 1);
    }
    l1.print();
    l1.removeFromLast();

    cout << "\nlast element is " << l1.getLastElement();
    cout << "\nFirst element is " << l1.getFirstElement();

    for (int i = 1; i < 20; i++)
    {
        l1.removeFromLast();
    }
    if (l1.isEmpty())
        cout << endl << "empty";
    else
        cout << endl << "not empty";
    l1.print();



    for (int i = 0; i < 20; i++)
    {
        l1.insertFromBeginning(i + 1);
    }
    l1.print();
    l1.removeFromBeginning();

    cout << "\nlast element is " << l1.getLastElement();
    cout << "\nFirst element is " << l1.getFirstElement();

    for (int i = 1; i < 20; i++)
    {
        l1.removeFromBeginning();
    }
    if (l1.isEmpty())
        cout << endl << "empty";
    else
        cout << endl << "not empty";
    l1.print();
    return 0;
}
