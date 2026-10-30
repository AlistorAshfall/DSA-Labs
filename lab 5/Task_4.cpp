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

    bool contains(T value) const {
        for (int i = 0; i < count; i++) {
            if (arr[(frontIdx + i) % capacity] == value) {
                return true;
            }
        }
        return false;
    }

    void enqueue(T value) {
        if (isFull()) {
            cout << "Ticket queue is full" << endl;
            return;
        }
        arr[(frontIdx + count) % capacity] = value;
        count++;
        cout << "Ticket " << value << " added" << endl;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "No pending tickets" << endl;
            return T();
        }
        T value = arr[frontIdx];
        frontIdx = (frontIdx + 1) % capacity;
        count--;
        return value;
    }

    T front() const {
        if (isEmpty()) {
            cout << "No pending tickets" << endl;
            return T();
        }
        return arr[frontIdx];
    }

    void display() const {
        if (isEmpty()) {
            cout << "No pending tickets" << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". Ticket " << arr[(frontIdx + i) % capacity] << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter maximum number of tickets: ";
    cin >> size;

    Queue<int> tickets(size);
    int choice = 0;

    while (choice != 5) {
        cout << "\n1. Add ticket\n2. Resolve ticket\n3. Next ticket\n4. Display pending tickets\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            cout << "Enter 4-digit ticket ID: ";
            cin >> id;
            if (id < 1000 || id > 9999) {
                cout << "Ticket ID must be 4 digits" << endl;
            }
            else if (tickets.contains(id)) {
                cout << "Ticket ID already exists" << endl;
            }
            else {
                tickets.enqueue(id);
            }
        }
        else if (choice == 2) {
            if (!tickets.isEmpty()) {
                cout << "Resolved ticket " << tickets.dequeue() << endl;
            }
            else {
                cout << "No pending tickets" << endl;
            }
        }
        else if (choice == 3) {
            if (!tickets.isEmpty()) {
                cout << "Next ticket: " << tickets.front() << endl;
            }
            else {
                cout << "No pending tickets" << endl;
            }
        }
        else if (choice == 4) {
            tickets.display();
        }
        else if (choice != 5) {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
