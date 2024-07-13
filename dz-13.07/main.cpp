#include <iostream>
using namespace std;

//Добавить в класс "Односвязный список" следующие функции : 
// * вставка элемента в заданную позицию,
// * удаление элемента по заданной позиции, 
// * поиск заданного элемента(функция возвращает позицию найденного элемента в случае успеха или NULL в случае неудачи).

struct Element
{
    // Данные
    char data;
    // Адрес следующего элемента списка
    Element* Next;
};

// Односвязный список
class List
{
    // Адрес головного элемента списка
    Element* Head;
    // Адрес головного элемента списка
    Element* Tail;
    // Количество элементов списка
    int Count;

public:
    // Конструктор
    List();
    // Деструктор
    ~List();

    // Добавление элемента в список
    // (Новый элемент становится последним)
    void Add(char data);

    // Удаление элемента списка
    // (Удаляется головной элемент)
    void Del();
    // Удаление всего списка
    void DelAll();

    // Распечатка содержимого списка
    // (Распечатка начинается с головного элемента)
    void Print();

    // Получение количества элементов, находящихся в списке
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
    // Изначально список пуст
    Head = Tail = NULL;
    Count = 0;
}

List::~List()
{
    // Вызов функции удаления
    DelAll();
}

int List::GetCount()
{
    // Возвращаем количество элементов
    return Count;
}

void List::Add(char data)
{
    // создание нового элемента
    Element* temp = new Element;

    // заполнение данными
    temp->data = data;
    // следующий элемент отсутствует
    temp->Next = NULL;
    // новый элемент становится последним элементом списка
    // если он не первый добавленный
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    // новый элемент становится единственным
    // если он первый добавленный
    else {
        Head = Tail = temp;
    }
}

void List::Del()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // перебрасываем голову на следующий элемент
    Head = Head->Next;
    // удаляем бывший головной элемент
    delete temp;
}

void List::DelAll()
{
    // Пока еще есть элементы
    while (Head != 0)
    {
        // Удаляем элементы по одному
        Del();
    }
}

void List::Print()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // Пока еще есть элементы
    while (temp != 0)
    {
        // Выводим данные
        cout << temp->data << " ";
        // Переходим на следующий элемент
        temp = temp->Next;
    }

    cout << "\n\n";
}

// Тестовый пример
void main()
{
    // Создаем объект класса List
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