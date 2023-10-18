#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <io.h>
#include <exception>
#include <stack>
#include <queue>
using namespace std;

enum Color
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown,
	LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void setColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, Esc = 27 };
void setCursor(int x, int y)
{
	COORD myCoords = { x,y };
	SetConsoleCursorPosition(hStdOut, myCoords);
}
template<typename myType>
class Queue
{
	int maxSize = 0;
	int realSize = -1;
	myType* Q = nullptr;
public:
	Queue(int maxSize)
	{
		this->maxSize = maxSize;
		Q = new myType[maxSize];
	}
	//метод для добавления элемента в хвост очереди (с предварительной проверкой на наличие места
	void addElement(myType var)
	{
		if (maxSize != realSize + 1)
		{
			Q[++realSize] = var;
		}
		else throw exception("FULL");
	}
	//метод для изъятия элемента с нулевой позиции (количество элементов уменьшается на 1)
	myType getElement()
	{
		//if
		myType temp = Q[0];
		for (size_t i = 1; i <= realSize; i++)
		{
			Q[i - 1] = Q[i];
		}
		realSize--;
		return temp;
		//исключение
	}
	//ДЗ
	//метод для возвращения размера
	void GetSize() const
	{
		return realSize + 1;
	}
	//метод для проверки пуста ли очередь
	int IsEmpty() const
	{
		//очередь пуста, когда ее текущий размер равен 0
		return realSize == -1;
	}
	//метод для проверки полна ли очередь
	void IsFull() const
	{
		//очередь заполнена когда ее размер равен максимальному
		return realSize == maxSize;
	}
	//показать очередь
	void Show() const
	{
		if (!IsEmpty())
		{
			for (int i = 0; i <= realSize; i++)
			{
				cout << Q[i] << endl;
			}
		}
	}
	//деструктор
	~Queue()
	{
		delete[]Q;
	}
	//конструктор копирования
	Queue(const Queue& right_Queue)
	{
		this->maxSize = right_Queue.size();
		Q = new myType[maxSize];
	}
};
	int main()
{
	setlocale(LC_ALL, "Rus");
	/*srand(time(0));
	try
	{

	}
	catch (const exception& ex)
	{
		cout << ex.what();
	}*/

	Queue<int>list(30);
	
	list.addElement(0);
	list.addElement(2);
	list.addElement(1);
	list.Show();
		/*stack<int> mySt;
		priority_queue <int> myQ;*/
};
