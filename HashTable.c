#include "stdio.h"
#include "stdbool.h"
#define _CAR_SECURE_NO_WARNINGS

int HashFunction(int number) {
	int index = number % 10;
	return index;
}
bool insert(int number,int* HashTable) {
	int index=HashFunction(number);
	if (HashTable[index] != -1)
		return false;
	else { HashTable[index] = number; return true; }
	
}
bool search(int number,int* HashTable) {
	int index = HashFunction(number);
	if (HashTable[index] != -1 && HashTable[index]== number)
		return true;
	return false;
}
int HashTable[10];
int main() {

	int number = 23;
	int result;
	for (int i = 0; i < 10; i++)
		HashTable[i] = -1;
	insert(number, HashTable);
	result = search(number, HashTable);
	
}