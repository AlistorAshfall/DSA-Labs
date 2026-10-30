#include <iostream>
using namespace std;

template <class T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};

template <class T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int capacity;
    int frontIdx;
    int rearIdx;
    int count;

public:
    myQueue(int size) {
        capacity = size;
        arr = new T[capacity];
        frontIdx = 0;
        rearIdx = -1;
        count = 0;
    }

    ~myQueue() {
        delete[] arr;
    }

    void enQueue(T value) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        rearIdx = (rearIdx + 1) % capacity;
        arr[rearIdx] = value;
        count++;
    }

    T deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return T();
        }
        T value = arr[frontIdx];
        frontIdx = (frontIdx + 1) % capacity;
        count--;
        return value;
    }

    T front() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return T();
        }
        return arr[frontIdx];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << arr[(frontIdx + i) % capacity] << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter maximum size of queue: ";
    cin >> size;

    myQueue<int> q(size);
    int choice = 0;

    while (choice != 7) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Is Empty\n5. Is Full\n6. Display\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int value;
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
        }
        else if (choice == 2) {
            if (q.isEmpty()) {
                cout << "Queue is empty" << endl;
            }
            else {
                cout << "Removed: " << q.deQueue() << endl;
            }
        }
        else if (choice == 3) {
            if (q.isEmpty()) {
                cout << "Queue is empty" << endl;
            }
            else {
                cout << "Front: " << q.front() << endl;
            }
        }
        else if (choice == 4) {
            cout << (q.isEmpty() ? "Yes, empty" : "No, not empty") << endl;
        }
        else if (choice == 5) {
            cout << (q.isFull() ? "Yes, full" : "No, not full") << endl;
        }
        else if (choice == 6) {
            q.display();
        }
        else if (choice != 7) {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
