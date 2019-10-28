#include <iostream>
//queue with two stack
using namespace std;

bool StackFull(int S[], int top, int len)
{
	return (top == len - 1);
}

bool StackEmpty(int S[], int top)
{
	return (top == -1);
}

void Push(int S[], int& top, int len, int num)
{
	if (StackFull(S, top, len))
		return; //error - overflow
	top++;
	S[top] = num;
}

int Pop(int S[], int& top)
{
	if (StackEmpty(S, top))
		return ' '; //error - underflow
	char result = S[top];
	top--;
	return result;
}
void Enquene(int S[], int& top, int len, int num) {

	Push(S, top, len, num);

}
int Dequeue(int S[], int& top, int S2[], int& top2, int len) {
	while (!StackEmpty(S, top))
	{
		Push(S2, top2, len, Pop(S, top));
	}
	int result = Pop(S2, top2);
	while (!StackEmpty(S, top))
	{
		Push(S, top, len, Pop(S2, top));
	}
	return result;
}
int main()
{
	//use const

	//Define Stack
	int S[10];
	int S2[10];
	int top = -1;
	int top2 = -1;

	int len = 10;
	int num;
	bool res1 = StackEmpty(S, top);
	for (int i = 0; i < 3; i++) {
		scanf_s("%d", &num);
		Enquene(S, top, len, num);
	}

	int result = Dequeue(S, top, S2, top2, len);
	printf("%d", result);

}