#include <iostream>
#include <iostream>
#include <stdlib.h>
using namespace std;
using std::cout;
using std::cin;

struct Node
{
    int x;
    Node* Next;
};
class List
{
    Node* Head, * Tail;
public:
    List() :Head(NULL), Tail(NULL) {};
    ~List();
    void Push(int x);
    void Peek();
    void Pop();
    friend ostream& operator << (ostream& stream, const List& a);
};
List::~List()
{
    Node* temp = Head;
    while (temp != 0)
    {
        temp = Head->Next;
        delete Head;
        Head = temp;
    }
}
void List::Push(int x)
{
    Node* temp = new Node;
    temp->x = x;
    temp->Next = NULL;

    if (Head != NULL)
    {
        Tail->Next = temp;
        Tail = temp;
    }
    else Head = Tail = temp;
}
ostream& operator << (ostream& stream, const List& a)
{
    Node* temp = a.Head;
    while (temp != NULL)
    {
        stream << temp->x << "";
        temp = temp->Next;
    }
    return stream << endl;
}
void List::Peek()
{
    cout << Head->x;
}
void List::Pop()
{
    Head = Head->Next;
}

class Exception
{
public:
    virtual const string GetError() const = 0;
};

inline const string Exception::GetError() const
{
    return "\n ERROR ";
}

class OverflowException : public Exception
{
public:
    virtual const string GetError() const override
    {
        return Exception::GetError() + "NOT ENOUGH FREE SPACE";
    }
};

class NoElementsException : public Exception
{
public:
    virtual const string GetError() const override
    {
        return Exception::GetError() + "NO ELEMENTS";
    }
};

void main()
{
    List lst;
    int size, count;
    cout << "Size = ";
    cin >> size;
    try {
        if (size >= 30) throw OverflowException();
        else {
            for (int i = 1; i <= size; i++)
            {
                cout << "Count " << i << "/" << size << " = ";
                cin >> count;
                lst.Push(count);
            }
            cout << lst;
            if (NULL) throw OverflowException();
            else {
            lst.Peek();
            lst.Pop();
        }
    }
}
    catch (Exception& exception)
    {
        exception.GetError();
    }
    cout << endl;
    cout << lst;
}

