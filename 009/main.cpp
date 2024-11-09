#include <iostream>

#include "MyStack.h"

using namespace std;

int main()
{
	MyStack<int> s;
	int c = 0;

	cout << s.empty() << endl;

	cout << s.top(c) << endl;
	cout << c << endl;

	s.push(1);
	cout << s.empty() << endl;
	cout << s.top(c) << endl;
	cout << c << endl;

	cout << s.pop() << endl;
	cout << s.empty() << endl;

	cout << s.pop() << endl;

	for (int i = 0; i < 100; i++)
	{
		s.push(i);
	}

	cout << s.top(c) << endl;
	cout << c << endl;

	cout << s.push(101) << endl;
	cout << s.top(c) << endl;
	cout << c << endl;

	for (int i = 0; i < 100; i++)
	{
		s.pop();
	}

	cout << s.top(c) << endl;
	cout << c << endl;

	return 0;
}
