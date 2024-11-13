#include<iostream>
using namespace std;

class deque {
    int a[100];
    int r, f, n;

public:
    deque(int size) {
        n = size;
        r = -1;
        f = -1;
    }

    void insert_rear();
    void insert_front();
    void delete_front();
    void delete_rear();
    void display();
};

void deque::insert_rear() {
    int x;
    cout << "\nEnter element you want to insert: ";
    cin >> x;

    if ((r + 1) % n == f) {
        cout << "\nQueue is full";
    } else if (r == -1 && f == -1) { // first element insertion
        r = f = 0;
        a[r] = x;
    } else {
        r = (r + 1) % n;
        a[r] = x;
    }
}

void deque::insert_front() {
    int x;
    cout << "\nEnter element you want to insert: ";
    cin >> x;

    if ((f - 1 + n) % n == r) {
        cout << "\nQueue is full";
    } else if (f == -1) { // first element insertion
        f = r = 0;
        a[f] = x;
    } else {
        f = (f - 1 + n) % n;
        a[f] = x;
    }
}

void deque::delete_front() {
    if (f == -1) {
        cout << "\nQueue is empty";
    } else if (f == r) { // only one element
        cout << "\nDeleted element: " << a[f];
        f = r = -1;
    } else {
        cout << "\nDeleted element: " << a[f];
        f = (f + 1) % n;
    }
}

void deque::delete_rear() {
    if (f == -1) {
        cout << "\nQueue is empty";
    } else if (f == r) { // only one element
        cout << "\nDeleted element: " << a[r];
        f = r = -1;
    } else {
        cout << "\nDeleted element: " << a[r];
        r = (r - 1 + n) % n;
    }
}

void deque::display() {
    if (f == -1) {
        cout << "\nQueue is empty";
    } else {
        cout << "\nQueue elements: ";
        int i = f;
        while (i != r) {
            cout << a[i] << " ";
            i = (i + 1) % n;
        }
        cout << a[r];
    }
}

int main() {
    int n, ch;
    cout << "\nEnter array size: ";
    cin >> n;

    deque dq(n);

    do {
        cout << "\n1. Insert rear\n2. Insert front\n3. Delete front\n4. Delete rear\n5. Display\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                dq.insert_rear();
                break;
            case 2:
                dq.insert_front();
                break;
            case 3:
                dq.delete_front();
                break;
            case 4:
                dq.delete_rear();
                break;
            case 5:
                dq.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    } while (ch != 0);

    return 0;
}
