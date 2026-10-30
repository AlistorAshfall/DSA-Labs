#include <iostream>
#include <string>
using namespace std;

struct Package {
    int id;
    string address;
    int startTime;
    int endTime;
};

ostream& operator<<(ostream& os, const Package& p) {
    os << "ID: " << p.id << " | Address: " << p.address << " | Window: " << p.startTime << " - " << p.endTime;
    return os;
}

template <class T>
class Queue {
private:
    T* arr;
    int capacity;
    int frontIdx;
    int count;

    void grow() {
        T* bigger = new T[capacity * 2];
        for (int i = 0; i < count; i++) {
            bigger[i] = arr[(frontIdx + i) % capacity];
        }
        delete[] arr;
        arr = bigger;
        frontIdx = 0;
        capacity *= 2;
    }

public:
    Queue(int size = 5) {
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

    void enqueue(T value) {
        if (count == capacity) {
            grow();
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
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << arr[(frontIdx + i) % capacity] << endl;
        }
    }
};

bool timeToDeliver(const Package& p, int currentTime) {
    return currentTime >= p.startTime && currentTime <= p.endTime;
}

void deliverNext(Queue<Package>& packages, Queue<Package>& expired, int currentTime) {
    while (!packages.isEmpty()) {
        Package p = packages.front();
        if (timeToDeliver(p, currentTime)) {
            cout << "Delivered package " << p.id << " to " << p.address << endl;
            packages.dequeue();
            return;
        }
        else if (currentTime > p.endTime) {
            cout << "Package " << p.id << " expired, skipping" << endl;
            expired.enqueue(packages.dequeue());
        }
        else {
            cout << "Package " << p.id << " window opens at " << p.startTime << ", cannot deliver yet" << endl;
            return;
        }
    }
    cout << "No packages to deliver" << endl;
}

int main() {
    Queue<Package> packages;
    Queue<Package> expired;
    int choice = 0;

    while (choice != 7) {
        cout << "\n1. Add package\n2. Deliver next package\n3. Front package\n4. Display packages\n5. Check front package time\n6. Display expired packages\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Package p;
            cout << "Enter package ID: ";
            cin >> p.id;
            cout << "Enter address: ";
            cin.ignore();
            getline(cin, p.address);
            cout << "Enter window start time (HHMM): ";
            cin >> p.startTime;
            cout << "Enter window end time (HHMM): ";
            cin >> p.endTime;
            if (p.startTime > p.endTime) {
                cout << "Start time cannot be after end time" << endl;
            }
            else {
                packages.enqueue(p);
                cout << "Package " << p.id << " added" << endl;
            }
        }
        else if (choice == 2) {
            int currentTime;
            cout << "Enter current time (HHMM): ";
            cin >> currentTime;
            deliverNext(packages, expired, currentTime);
        }
        else if (choice == 3) {
            if (!packages.isEmpty()) {
                cout << packages.front() << endl;
            }
            else {
                cout << "Queue is empty" << endl;
            }
        }
        else if (choice == 4) {
            packages.display();
        }
        else if (choice == 5) {
            if (packages.isEmpty()) {
                cout << "Queue is empty" << endl;
            }
            else {
                int currentTime;
                cout << "Enter current time (HHMM): ";
                cin >> currentTime;
                if (timeToDeliver(packages.front(), currentTime)) {
                    cout << "Front package can be delivered now" << endl;
                }
                else {
                    cout << "Front package cannot be delivered now" << endl;
                }
            }
        }
        else if (choice == 6) {
            expired.display();
        }
        else if (choice != 7) {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
