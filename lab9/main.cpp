//Heap sort
#include <iostream>
using namespace std;
#define N 10

void Heapify(int mas[], int n, int i)
{
    int largest = i;                          
    int left = 2 * i + 1;         
    int right = 2 * i + 2;       

    if (left < n && mas[left] > mas[largest])      
        largest = left;
    if (right < n && mas[right] > mas[largest])     
        largest = right;
    if (largest != i) 
    {                           
        swap(mas[i], mas[largest]);
        Heapify(mas, n, largest);                
    }
}

void Sort(int mas[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)        //Building a heap (regroup the array)
        Heapify(mas, n, i);

    for (int i = n - 1; i >= 0; i--) 
    {              
        swap(mas[0], mas[i]);              
        Heapify(mas, i, 0);                    
    }
}


int main()
{
    int mas[N];
    for (int i = 0; i < N; i++)
        mas[i] = rand() % 100;
    for (int i = 0; i < N; i++)
        cout << mas[i] << endl;// array
    cout << "=================" << endl;
    Sort(mas, N);
    for (int i = 0; i < N; i++)
        cout << mas[i] << endl;
    return 0;
}

//O(nlogn)
