#include <iostream>
using namespace std;

template <class T>
class Queue {
private:
    T* arr;
    int capacity;
    int frontIdx;
    int count;

public:
    Queue(int size) {
        capacity = size;
        arr = new T[capacity];
        frontIdx = 0;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    int size() const {
        return count;
    }

    void enqueue(T value) {
        if (isFull()) {
            return;
        }
        arr[(frontIdx + count) % capacity] = value;
        count++;
    }

    T dequeue() {
        if (isEmpty()) {
            return T();
        }
        T value = arr[frontIdx];
        frontIdx = (frontIdx + 1) % capacity;
        count--;
        return value;
    }

    T front() const {
        if (isEmpty()) {
            return T();
        }
        return arr[frontIdx];
    }

    void display() const {
        for (int i = 0; i < count; i++) {
            cout << arr[(frontIdx + i) % capacity] << " ";
        }
        cout << endl;
    }
};

void reverseFirstK(Queue<int>& q, int k) {
    int total = q.size();
    if (k > total) {
        k = total;
    }
    if (k <= 1) {
        return;
    }

    int* temp = new int[k];
    for (int i = 0; i < k; i++) {
        temp[i] = q.dequeue();
    }
    for (int i = k - 1; i >= 0; i--) {
        q.enqueue(temp[i]);
    }
    for (int i = 0; i < total - k; i++) {
        q.enqueue(q.dequeue());
    }
    delete[] temp;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Queue is empty" << endl;
        return 0;
    }

    Queue<int> q(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        q.enqueue(value);
    }

    int k;
    cout << "Enter K: ";
    cin >> k;

    cout << "Queue: ";
    q.display();

    reverseFirstK(q, k);

    cout << "Output: ";
    q.display();

    return 0;
}
