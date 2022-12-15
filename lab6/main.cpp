//Selection sort
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
    for (int i = 0; i < N - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < N; j++)
        {
            if (mas[j] < mas[min])
            {
                min = j;              //find minimum
            }
        }
        if (min != i)
        {
            std::swap(mas[i], mas[min]); //sort
        }
    }

	for (int i = 0; i < N; i++)
		cout << mas[i] << endl;
}
//worst O(n^2)
//medium O(n^2)
//best O(n^2)