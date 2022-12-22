//Merge sort
#include <iostream>
using namespace std;

void Merge(int* A, int first, int last) 
{
    int middle, start, final;
    int* mas = new int[100];
    middle = (first + last) / 2;           
    start = first;                        
    final = middle + 1;                   
    for (int i = first; i <= last; i++)      
        if ((start <= middle) && ((final > last) || (A[start] < A[final]))) 
        {
            mas[i] = A[start];
            start++;
        }
        else 
        {
            mas[i] = A[final];
            final++;
        }
    for (int i = first; i <= last; i++)
        A[i] = mas[i];
    delete[] mas;
};

void MergeSort(int* A, int first, int last) 
{
    if (first < last) 
    {
        MergeSort(A, first, (first + last) / 2);     
        MergeSort(A, (first + last) / 2 + 1, last);   
        Merge(A, first, last);                        
    }
}


int main() 
{
    int n;
    cout << "Enter array size" <<endl;
    cin >> n;
    int* mas = new int[100];
    for (int i = 1; i <= n; i++)
        mas[i] = rand() % 100;
    for (int i = 1; i <= n; i++)
        cout << mas[i] << endl; //array
    cout << "=================" << endl;
    MergeSort(mas, 1, n);
    for (int i = 1; i < n; i++)
        cout << mas[i] << endl;
    delete[]mas;
}

//O(nlogn)
