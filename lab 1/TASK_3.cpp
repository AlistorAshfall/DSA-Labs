#include <iostream>
#include <string>
using namespace std;

template <typename T, size_t N>
int binarySearch(T(&A)[N], const T& value)
{
    int low = 0;
    int high = N - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (A[mid] == value)
        {
            return mid;
        }
        else if (A[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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
    int intArray[5] = { 11, 12, 22, 25, 64 };
    int intKey = 22;
    int intIndex = binarySearch(intArray, intKey);
    printSearchResult(intIndex, intKey);

    float floatArray[4] = { 0.57, 1.62, 2.71, 3.14 };
    float floatKey = 2.71;
    int floatIndex = binarySearch(floatArray, floatKey);
    printSearchResult(floatIndex, floatKey);

    string stringArray[4] = { "apple", "banana", "grape", "orange" };
    string stringKey = "grape";
    int stringIndex = binarySearch(stringArray, stringKey);
    printSearchResult(stringIndex, stringKey);

    return 0;
}