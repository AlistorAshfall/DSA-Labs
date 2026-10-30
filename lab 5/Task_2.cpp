#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    T* arr;
    int capacity;
    int topIdx;

public:
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        topIdx = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T value) {
        arr[++topIdx] = value;
    }

    T pop() {
        return arr[topIdx--];
    }

    T top() const {
        return arr[topIdx];
    }

    T at(int i) const {
        return arr[i];
    }

    int size() const {
        return topIdx + 1;
    }

    bool isEmpty() const {
        return topIdx == -1;
    }
};

template <class T>
class QueueUsingStacks {
private:
    Stack<T> inStack;
    Stack<T> outStack;
    int capacity;

    void transfer() {
        if (outStack.isEmpty()) {
            while (!inStack.isEmpty()) {
                outStack.push(inStack.pop());
            }
        }
    }

public:
    QueueUsingStacks(int size) : inStack(size), outStack(size) {
        capacity = size;
    }

    bool isEmpty() const {
        return inStack.isEmpty() && outStack.isEmpty();
    }

    bool isFull() const {
        return inStack.size() + outStack.size() == capacity;
    }

    void enQueue(T value) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        inStack.push(value);
    }

    T deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return T();
        }
        transfer();
        return outStack.pop();
    }

    T front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return T();
        }
        transfer();
        return outStack.top();
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = outStack.size() - 1; i >= 0; i--) {
            cout << outStack.at(i) << endl;
        }
        for (int i = 0; i < inStack.size(); i++) {
            cout << inStack.at(i) << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter maximum size of queue: ";
    cin >> size;

    QueueUsingStacks<int> q(size);
    int choice = 0;

    while (choice != 5) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Exit\n";
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
            q.display();
        }
        else if (choice != 5) {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
