#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int top=-1;
int a[MAX];

bool push(int x)
{
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
		a[++top] = x;
		// cout << x << "\n";
		return true;
	}
}

int pop()
{
	if (top < 0) {
		cout << "Stack Underflow";
		return 0;
	}
	else {
		int x = a[top--];
		return x;
	}
}
int peek()
{
	if (top < 0) {
		cout << "Stack is Empty";
		return 0;
	}
	else {
		int x = a[top];
		return x;
	}
}

bool isEmpty()
{
	return (top < 0);
}

int main()
{
	cout << isEmpty() << endl;
	push(10);
	push(20);
	push(30);
	cout << pop() << " \n";

	return 0;
}
