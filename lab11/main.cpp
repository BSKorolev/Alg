//Quick sort
#include <iostream>
using namespace std;
#define N 10

void Sort(int mas[N], int a, int b)
{
    if (a >= b)
        return;
    int m = (rand() * rand()) % (b - a + 1) + a; //support element
    int k = mas[m];
    int l = a - 1; //left
    int r = b + 1; //right
    while (107)
    {
        do l = l + 1; while (mas[l] < k);
        do r = r - 1; while (mas[r] > k);
        if (l >= r)
            break;
        swap(mas[l], mas[r]);
    }
    r = l;
    l = l - 1;
    Sort(mas, a, l);
    Sort(mas, r, b);
}

int main() 
{
    int mas[N];
    for (int i = 0; i < N; i++)
        mas[i] = rand() % 100;
    for (int i = 0; i < N; i++)
        cout << mas[i] << endl; //array
    cout << "================" << endl;
    int n = N;
    int a = 0;
    int b = N - 1;
    Sort(mas, a, b);
    for (int i = 0; i < N; i++)
        cout << mas[i] << endl;
}

//worst - O(n^2)
//medium, best - O(nlogn)