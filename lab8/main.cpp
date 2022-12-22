//Radix sort
#include <iostream>
using namespace std;
#define N 10

int radix_value(int x, int rad) //splitting into radix
{
    while (rad > 1)
    {
        x /= 10;
        rad--;
    }
    return x % 10;
}

void radix_sort(int mas2[N][N], int mas[N], int rad)
{
    int mas_col[N], i, j, tmp = 0;
    for (i = 0; i < N; i++)
        mas_col[i] = 0;
    for (i = 0; i < N; i++)
    {
        int a = radix_value(mas[i], rad);
        mas2[mas_col[a]][a] = mas[i];
        mas_col[a]++;
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < mas_col[i]; j++)
        {
            mas[tmp] = mas2[j][i];
            tmp++;
        }
    }
}
int main()
{
    int mas[N];
    int mas2[N][N];
    int rad, i;
    for (int i = 0; i < N; i++)
        mas[i] = rand() % 100;
    for (int i = 0; i < N; i++)
        cout << mas[i] << endl;// array
    cout << "=================" << endl;
    for (rad = 1; rad < 5; rad++)
        radix_sort(mas2, mas, rad);
    for (int i = 0; i < N; i++)
        cout << mas[i] << endl;
}
// O(n)
