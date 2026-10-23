#include <iostream>
#include <utility>
using namespace std;

template <typename T, size_t N>
void printArray(T(&A)[N])
{
    for (size_t i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

template <typename T, size_t N>
void selectionSort(T(&A)[N])
{
    for (size_t i = 0; i + 1 < N; i++)
    {
        size_t smallSub = i;
        for (size_t j = i + 1; j < N; j++)
        {
            if (A[j] < A[smallSub])
            {
                smallSub = j;
            }
        }
        swap(A[i], A[smallSub]);
    }
}

int main()
{
    int intArray[5] = { 64, 25, 12, 22, 11 };
    cout << "Original integer array: ";
    printArray(intArray);
    selectionSort(intArray);
    cout << "Sorted integer array: ";
    printArray(intArray);

    return 0;
}