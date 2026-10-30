#include <iostream>
#include <string>
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

    void enqueue(T value) {
        if (isFull()) {
            cout << "Print queue is full" << endl;
            return;
        }
        arr[(frontIdx + count) % capacity] = value;
        count++;
        cout << "Added: " << value << endl;
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
        if (isEmpty()) {
            cout << "No documents in queue" << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << arr[(frontIdx + i) % capacity] << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter maximum number of print jobs: ";
    cin >> size;

    Queue<string> jobs(size);
    int choice = 0;

    while (choice != 5) {
        cout << "\n1. Add print job\n2. Print document\n3. Check front document\n4. Display print jobs\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            cout << "Enter document name: ";
            cin.ignore();
            getline(cin, name);
            jobs.enqueue(name);
        }
        else if (choice == 2) {
            if (!jobs.isEmpty()) {
                cout << "Printing: " << jobs.dequeue() << endl;
            }
            else {
                cout << "No documents in queue" << endl;
            }
        }
        else if (choice == 3) {
            if (!jobs.isEmpty()) {
                cout << "Front document: " << jobs.front() << endl;
            }
            else {
                cout << "No documents in queue" << endl;
            }
        }
        else if (choice == 4) {
            jobs.display();
        }
        else if (choice != 5) {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
