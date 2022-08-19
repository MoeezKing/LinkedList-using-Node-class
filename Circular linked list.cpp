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
    Node(int data = -9999, Node* next = NULL, Node* previous = NULL)
    {
        setData(data);
        setNext(next);
        setPrevious(previous);
    }
};
class LinkedList
{
    Node* head;
    int length;
public:
    Node* getHead()
    {
        return head;
    }
    int getLength()
    {
        return length;
    }
    void setHead(Node* head)
    {
        this->head = head;
    }
    LinkedList()
    {
        head = NULL;
        length = 0;
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
    void insertAtStart(int val)
    {
        Node* temp = new Node(val);
        if (isEmpty())
        {
            head = temp;
            head->setNext(head);
            head->setPrevious(head);
            length++;
        }
        else
        {
            Node* last = head->getPrevious();
            temp->setNext(head);
            temp->setPrevious(last);
            head->setPrevious(temp);
            last->setNext(temp);
            head = temp;
            length++;
        }
    }
    void insertAtEnd(int val)
    {
        Node* temp = new Node(val);
        if (isEmpty())
        {
            head = temp;
            head->setNext(head);
            head->setPrevious(head);
            length++;
        }
        else
        {
            Node* last = head->getPrevious();
            temp->setNext(head);
            temp->setPrevious(last);
            last->setNext(temp);
            head->setPrevious(temp);
            length++;
        }
    }
    bool removeFromStart()
    {
        if (isEmpty())
            return false;
        else
        {
            if (length == 1)
            {
                delete head;
                head = NULL;
                length--;
                return true;
            }
            Node* hnext = head->getNext();
            Node* hprev = head->getPrevious();
            delete head;
            hnext->setPrevious(hprev);
            hprev->setNext(hnext);
            head = hnext;
            length--;
            return true;
        }
    }
    bool removeFromEnd()
    {
        if (isEmpty())
            return false;
        else
        {
            if (length == 1)
            {
                delete head;
                head = NULL;
                length--;
                return true;
            }
            Node* end = head->getPrevious();
            Node* sndlast = end->getPrevious();
            head->setPrevious(sndlast);
            sndlast->setNext(head);
            delete end;
            length--;
            return true;
        }
    }
    void print()
    {
        if (isEmpty())
            return;

        Node* temp = head;
        while (temp->getNext() != head)
        {
            cout << temp->getData() << "-->";
            temp = temp->getNext();
        }
        cout << temp->getData() <<"-->"<< head->getData() << " (head)\n";
    }
    int getFirstElement()
    {
        if (!isEmpty())
            return head->getData();
        else
            cout << "\nEmpty linked list(-9999) \n"; return -9999;
    }
    int getLAstElement()
    {
        if (!isEmpty())
        {
            Node* last = head->getPrevious();
            return last->getData();
        }
        else
            cout << "\nEmpty linked list(-9999) \n"; return -9999;
    }
};
int main()
{
    LinkedList l1;
    l1.insertAtStart(1);
    l1.insertAtEnd(2);
    l1.insertAtStart(9);
    l1.insertAtEnd(2);
    l1.print();
    
    l1.removeFromEnd();
    l1.removeFromStart();
    l1.removeFromEnd();
    l1.removeFromStart();
    l1.print();
    cout<<l1.getFirstElement();
    return 0;
}
