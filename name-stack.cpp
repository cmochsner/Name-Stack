#include <iostream>
#include <string>

using namespace std;

template <class T>
struct node
{
	T letter;
	node<T> *next = {};
};

template <class T>
class stack
{
	node<T> *top;
	public:
		stack()
		{
			top = {};
		}
		bool isEmpty()
		{
			if (top == NULL)
			{
				return true;
			}

			return false;
		}
		void push(T l)
		{
			node<T> *newnode = new node<T>;

			newnode->letter = l;
			newnode->next = top;

			top = newnode;
		}
		T pop()
		{
			if (isEmpty())
			{
				return {};
			}

			T letter = top->letter;

			node<T> *temp = top;
			top = top->next;

			free(temp);
			
			return letter;
		}
		void print()
		{
			if (!isEmpty())
			{
				T l = pop();
				print();
				cout << l;
			}
		}
};

template <class T>
void addName(string name, stack<T> &s);

int main()
{
	cout << "Welcome to the Name Stack Program!" << endl;
	
	stack<char> s;
	string name;
	int choice = 0;

	cout << "Enter the name you'd like to add to your stack." << endl;
	cin >> name;

	addName(name, s);

	while (choice != 4)
	{
		cout << "Choose what you'd like to do to your name." << endl;
		cout << "1: Print my name (empties stack)." << endl;
		cout << "2: Push a new letter to my name. " << endl;
		cout << "3: Pop the last letter from my name. " << endl;
		cout << "4: Exit the program." << endl;
		cin >> choice;

		switch (choice)
		{
			case 1:
			{
				s.print();

				cout << "\nAfter printing your name, the stack is now empty. If you'd like to push a new name, type it below. Type 4 to exit." << endl;
				cin >> name;
				
				if (name == "4")
				{
					choice = 4;
				}
				else
				{
					addName(name, s);
				}
			}
			break;
			case 2:
			{
				char ch;

				cout << "What letter would you like to push?" << endl;
				cin >> ch;

				s.push(ch);
			}
			break;
			case 3:
			{
				s.pop();
			}
			break;
			case 4:
				break;
			default:
			{
				cout << "Invalid choice. Try again." << endl;
			}
			break;
		}
	}

	return 0;
}

template<class T>
void addName(string name, stack<T> &s)
{
	int length = name.length();
	for (int i = 0; i < length; i++)
	{
		s.push(name[i]);
	}
}