#include <iostream>
#include <string>
using namespace std;

template <typename T, size_t N>
int linearSearch(T(&A)[N], const T& value)
{
    for (size_t i = 0; i < N; i++)
    {
        if (A[i] == value)
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
void printSearchResult(int index, const T& key)
{
    if (index == -1)
    {
        cout << key << " not found in the array" << endl;
    }
    else
    {
        cout << key << " found at index " << index << endl;
    }
}

int main()
{
    int intArray[5] = { 64, 25, 12, 22, 11 };
    int intKey = 12;
    int intIndex = linearSearch(intArray, intKey);
    printSearchResult(intIndex, intKey);

    float floatArray[4] = { 3.14, 2.71, 1.62, 0.57 };
    float floatKey = 1.62;
    int floatIndex = linearSearch(floatArray, floatKey);
    printSearchResult(floatIndex, floatKey);

    string stringArray[4] = { "apple", "orange", "banana", "grape" };
    string stringKey = "banana";
    int stringIndex = linearSearch(stringArray, stringKey);
    printSearchResult(stringIndex, stringKey);

    return 0;
}