#include <iostream>
using namespace std;

//�������� � ����� "����������� ������" ��������� ������� : 
// * ������� �������� � �������� �������,
// * �������� �������� �� �������� �������, 
// * ����� ��������� ��������(������� ���������� ������� ���������� �������� � ������ ������ ��� NULL � ������ �������).

struct Element
{
    // ������
    char data;
    // ����� ���������� �������� ������
    Element* Next;
};

// ����������� ������
class List
{
    // ����� ��������� �������� ������
    Element* Head;
    // ����� ��������� �������� ������
    Element* Tail;
    // ���������� ��������� ������
    int Count;

public:
    // �����������
    List();
    // ����������
    ~List();

    // ���������� �������� � ������
    // (����� ������� ���������� ���������)
    void Add(char data);

    // �������� �������� ������
    // (��������� �������� �������)
    void Del();
    // �������� ����� ������
    void DelAll();

    // ���������� ����������� ������
    // (���������� ���������� � ��������� ��������)
    void Print();

    // ��������� ���������� ���������, ����������� � ������
    int GetCount();

    void AddIndex(char c, int numb)
    {
        int i = 1;
        Element* temp = Head;
        while (i < numb)
        {
            temp = temp->Next;
            i++;
        }
        // cout << temp->data << endl;

        Element* nElement = new Element;
        nElement->data = c;
        nElement->Next = temp->Next;
        temp->Next = nElement;
    }
    void DelIndex(int number)
    {
        Element* prevdel = Head;
        Element* del;
        int i = 1;
        while (i < number - 1)
        {
            prevdel = prevdel->Next;
            i++;
        }
        del = prevdel->Next;
        prevdel->Next = del->Next;
        delete del;
    }
    void FindIndex(char c)
    {
        int i = 0;
        Element* temp = Head;
        if (temp->data == c)
        {
            cout << "Element found under this index -> " << i << endl << endl;
        }
        temp = temp->Next;
        i++;
    }
};

List::List()
{
    // ���������� ������ ����
    Head = Tail = NULL;
    Count = 0;
}

List::~List()
{
    // ����� ������� ��������
    DelAll();
}

int List::GetCount()
{
    // ���������� ���������� ���������
    return Count;
}

void List::Add(char data)
{
    // �������� ������ ��������
    Element* temp = new Element;

    // ���������� �������
    temp->data = data;
    // ��������� ������� �����������
    temp->Next = NULL;
    // ����� ������� ���������� ��������� ��������� ������
    // ���� �� �� ������ �����������
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    // ����� ������� ���������� ������������
    // ���� �� ������ �����������
    else {
        Head = Tail = temp;
    }
}

void List::Del()
{
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ������������� ������ �� ��������� �������
    Head = Head->Next;
    // ������� ������ �������� �������
    delete temp;
}

void List::DelAll()
{
    // ���� ��� ���� ��������
    while (Head != 0)
    {
        // ������� �������� �� ������
        Del();
    }
}

void List::Print()
{
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ���� ��� ���� ��������
    while (temp != 0)
    {
        // ������� ������
        cout << temp->data << " ";
        // ��������� �� ��������� �������
        temp = temp->Next;
    }

    cout << "\n\n";
}

// �������� ������
void main()
{
    // ������� ������ ������ List
    List lst;
    lst.Add('H');
    lst.Add('e');
    lst.Add('l');
    lst.Add('l');
    lst.Add('o');

    lst.Print();

    lst.FindIndex('H');
    lst.Print();

    lst.Del();
    lst.Print();

    lst.AddIndex('X', 2);
    lst.Print();

    lst.DelIndex(3);
    lst.Print();

   
}