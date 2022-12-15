//ShellSort
#include <iostream>
using namespace std;
#define N 10

int main()
{
	int mas[N];
	for (int i = 0; i < N; i++)
		mas[i] = rand() % 100; 
	for (int i = 0; i < N; i++)
		cout << mas[i] << endl;// array
	cout << "=================" << endl;
    int i, j;
    for (int k = N / 2; k > 0; k /= 2) //splitting into sub-arrays
        for (i = k; i < N; i++)
        {
            for (j = i; j >= k; j -= k)
            {
                if (mas[j] < mas[j - k])
                    std::swap(mas[j], mas[j - k]);
                else
                    break;
            }
        }
	for (int i = 0; i < N; i++)
		cout << mas[i] << endl;
}
// worst O(n^2)
// best O(nlog^2n)