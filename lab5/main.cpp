#include <iostream>
using namespace std;
#define N 10


int main() 
{
	int mas[N];
	for (int i = 0; i < N; i++)
		mas[i] = rand() % 100;
	for (int i = 0; i < N; i++)
		cout << mas[i] << endl; //array
	cout << "=================" << endl; 
	for (int i = 1; i < N; i++) //start from the second position 
		for (int j = i; j > 0 && mas[j - 1] > mas[j]; j--)
			swap(mas[j - 1], mas[j]);
	for (int i = 0; i < N; i++)
		cout << mas[i] << endl;
}
//worst O(n^2)
//medium O(n^2)
//best O(n)