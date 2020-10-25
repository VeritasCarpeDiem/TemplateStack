#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack
{
private:
	int capacity = 10;
	int count;
	unique_ptr<T[]> arr; //unique ptr to array based stack
public:
	Stack()
	{
		arr = make_unique <T[]>(capacity);
	}
	~Stack()
	{
		Clear();
	}
	void Push(T value) //Adds a generic value to the top of the stack
	{
		EnsureCapacity(); //checks if stack is full. If it is, then it creates a new stack double the original size

		arr[count] = value;
		count++;
	}
	T Pop() //removes and returns the value at the top of the stack
	{
		T value = Peek();
		count--;
		return value;
	}
	T Peek() //returns the generic value at the top of the stack
	{
		if (isEmpty())
		{
			cout << "Stack is empty!" << endl;
			return T();
		}
		return arr[count - 1];
	}

	bool isEmpty() //checks to see if stack is empty
	{
		return count == 0;
	}

	void Clear()//Empties and resets the stack
	{
		unique_ptr<T[]> temp = make_unique<T[]>(capacity);
		arr = move(temp);
		count = 0;
	}
	void EnsureCapacity()
	{
		if (capacity == count) //if you reached maximum capacity, resize the array to double the original size
		{
			capacity = 2 * capacity;
			unique_ptr<T[]> temp = make_unique<T[]>(capacity);
			for (int i = 0; i < capacity/2; i++)
			{
				temp[i] = arr[i];
			}
			arr = move(temp);//transfer ownership of the temp ptr to the original arr ptr
		}
	}
};

int main()
{
	Stack<int> intStack;
	Stack<string> stringStack;

	intStack.Peek();

	//Push values onto the int Stack
	intStack.Push(1);
	intStack.Push(2);
	intStack.Push(3);
	//Pop values off the int Stack
	cout << intStack.Pop() << endl; //3
	cout << intStack.Pop() << endl; //2
	cout << intStack.Pop() << endl; //1

	//Push values into the string stack
	stringStack.Push("Jin");
	stringStack.Push("there");
	stringStack.Push("Hello");
	//Pop values off the string stack
	cout << stringStack.Pop() << endl; //Hello
	cout << stringStack.Pop() << endl; //there
	cout << stringStack.Pop() << endl; //Jin

	
	return 0;
}


#pragma region uniquePtr
/*unique_ptr<int[]> ptr1;
	ptr1 = make_unique<int[]>(5);
	for (size_t i = 0; i < 5; i++)
	{
		ptr1[i] = i;
		cout << ptr1[i];
	}

	auto ptr2 = make_unique<int[]>(3);
	for (size_t i = 0; i < 3; i++)
	{
		ptr2[i] = ptr1[i];
	}
	ptr2 = move(ptr1);
	;*/
#pragma endregion just reviewing unique ptrs
