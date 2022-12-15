//Comb sort
#include <iostream>
using namespace std;
#define N 10

int main() 
{
	int mas[N];
	for (int i = 0; i < N; i++)
		mas[i] = rand() % 100; //filling array
	for (int i = 0; i < N; i++)
		cout << mas[i] << endl; 
	cout << "=================" << endl;
	double factor = 1.2473309; //reduction factor
	int k = N - 1; //step
	while (k >= 1) 
	{
		for (int i = 0; i + k < N; i++) 
		{
			if (mas[i] > mas[i + k]) 
			{
				std::swap(mas[i], mas[i + k]);
			}
		}
		k /= factor;
	}
	for (int i = 0; i < N; i++)
		cout << mas[i] << endl;
}
// worst n^2
// best n*logn
