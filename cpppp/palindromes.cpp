#include <bits/stdc++.h>
#include <string>
#include <cstring>

#define MAX_ITEMS 50

typedef char typeName;

class Stack
{
public:
	Stack();
	Stack(int);
	~Stack();
	bool Push(typeName);
	typeName Pop();
	bool IsFull();
	bool IsEmpty();
	void Show();
private:
	int top;
	typeName items[MAX_ITEMS];
};


static Stack stackChar;
static Queue queueChar;

Queue::Queue()
{
	front = 0;
	rear = 0;
}
Queue::Queue(int numberOfItems)
{
	front = 0;
	rear = numberOfItems;
	cout << "Creat a Queue: ";
	for (int i = 0; i< numberOfItems; i++)
	{
		items[i] = i + 65;
		cout << items[i] << ", ";
	}
	cout << endl;
}
Queue::~Queue()
{
}
bool Queue::EnQueue(typeName newItem)
{
	if (!IsFull())
	{
		cout << "Enqueue the item '" << newItem << "' into the queue. " << endl;
		items[rear] = newItem;
		rear = (rear + 1) % MAX_ITEMS;
		return true;
	}
	else
	{
		return false;
	}
}
typeName Queue::DeQueue()
{
	if (!IsEmpty())
	{
		typeName temp = items[front];
		cout << "Dequeue the item '" << items[front] << "' from the queue. " << endl;
		front = (front + 1) % MAX_ITEMS;
		return temp;
	}
	else
	{
		return false;
	}
	
}
bool Queue::IsEmpty()
{
	if (rear == front)
	{
		//cout << "Queue is Empty!" << endl;
		return true;
	}
	else
	{
		//cout << "Queue is NOT Empty!" << endl;
		return false;
	}
}
bool Queue::IsFull()
{
	if ((rear + 1) % MAX_ITEMS == front)
	{
		//cout << "Queue is Full!" << endl;
		return true;
	}
	else
	{
		//cout << "Queue is NOT Full!" << endl;
		return false;
	}
}
void Queue::Show()
{
	cout << "Show the Stack: ";
	for (int i = front; i< rear; i++)
	{
		cout << items[i] << ", ";
	}
	cout << endl;
}
void Push(char* str, int charSize)
{
	for (int i = 0; i < charSize; i++)
	{
		stackChar.Push(str[i]);
	}
	
	stackChar.Show();
}

void Enqueue(char* str, int charSize)
{
	for (int i = 0; i < charSize; i++)
	{
		queueChar.EnQueue(str[i]);
	}

	queueChar.Show();
}

bool palindrome()
{
	while (!stackChar.IsEmpty()||!queueChar.IsEmpty())
	{
		if (stackChar.Pop()!=queueChar.DeQueue())
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cout << "Please enter the word you want to test:" << endl;
	

	//?????string, ????char?????
	char *cstr;
	string str;
	cin >> str;

	cstr = new char[str.size() + 1];
	strcpy(cstr, str.c_str());

	cout << cstr << endl;
	cout << str.size() << endl;
	
	Push(cstr, str.size());
    Enqueue(cstr, str.size());

	
	if (palindrome())
	{
		cout << "It is a palindrome word." << endl;
	}
	else
	{
		cout << "It is NOT a palindrome word." << endl;
	}


	system("pause");
	return 0;
}