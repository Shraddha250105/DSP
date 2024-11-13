#include <iostream>
using namespace std;

class LMS {
    int price;
    string tt, aut;
    LMS *next;
    public:
    void accept();
    void display();
    void search();
    void modify();
    void delete_position();
    void delete_first();
    void delete_last();
}*start=NULL;

void LMS::accept() {
    LMS *newnode = new LMS;
    cout << "Enter Book title, author, price: ";
    cin >> newnode->tt >> newnode->aut >> newnode->price;

    if (start == nullptr) {
        start = newnode;
    } else {
        LMS *temp = start;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void LMS::display() {
    LMS *temp = start;
    while (temp != nullptr) {
        cout << "\n" << temp->tt << "\t" << temp->aut << "\t" << temp->price;
        temp = temp->next;
    }
}

void LMS::search() {
    string title;
    int f = 0;
    cout << "\nEnter a book you want to search: ";
    cin >> title;
    LMS *temp = start;

    while (temp != nullptr) {
        if (title == temp->tt) {
            cout << "\n" << temp->tt << "\t" << temp->aut << "\t" << temp->price;
            f = 1;
            break; // Exit loop if book is found
        }
        temp = temp->next;
    }

    if (f == 1) {
        cout << "\nFound";
    } else {
        cout << "\nNot found";
    }
}

void LMS::modify() {
    string title;
    int f = 0;
    cout << "\nEnter title you want to modify: ";
    cin >> title;
    LMS *temp = start;

    while (temp != nullptr) {
        if (title == temp->tt) {
            cout << "Enter new title, author, and price: ";
            cin >> temp->tt >> temp->aut >> temp->price;
            f = 1;
            break; // Exit loop if modification is done
        }
        temp = temp->next;
    }

    if (f == 1) {
        cout << "\nModification successful";
    } else {
        cout << "\nBook not found";
    }
}

void LMS::delete_first() {
    if (start == nullptr) {
        cout << "\nList is empty";
        return;
    }

    LMS *temp = start;
    start = start->next;
    cout << "\nDeleted: " << temp->tt << "\t" << temp->aut << "\t" << temp->price;
    delete temp;
}

void LMS::delete_last() {
    if (start == nullptr) {
        cout << "\nList is empty";
        return;
    }

    if (start->next == nullptr) {
        cout << "\nDeleted: " << start->tt << "\t" << start->aut << "\t" << start->price;
        delete start;
        start = nullptr;
        return;
    }

    LMS *temp = start;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    cout << "\nDeleted: " << temp->next->tt << "\t" << temp->next->aut << "\t" << temp->next->price;
    delete temp->next;
    temp->next = nullptr;
}

void LMS::delete_position() {
    string title;
    cout << "\nEnter title of the book to delete: ";
    cin >> title;

    if (start == nullptr) {
        cout << "\nList is empty";
        return;
    }

    if (start->tt == title) {
        delete_first();
        return;
    }

    LMS *temp = start;
    while (temp->next != nullptr && temp->next->tt != title) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "\nBook not found";
        return;
    }

    LMS *pos = temp->next;
    temp->next = pos->next;
    cout << "\nDeleted: " << pos->tt << "\t" << pos->aut << "\t" << pos->price;
    delete pos;
}

int main() {
    int ch;
    LMS s;
    do {
        cout << "\n1. Accept\n2. Display\n3. Search\n4. Modify\n5. Delete first\n6. Delete last\n7. Delete position\n";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
            s.accept(); 
            break;
            
            case 2: 
            s.display(); 
            break;
            
            case 3:
            s.search(); 
            break;
            
            case 4: 
            s.modify(); 
            break;
            
            case 5:
            s.delete_first();
            break;
            
            case 6:
            s.delete_last();
            break;
            
            case 7:
            s.delete_position();
            break;
            
        }
    } while (ch != 0);
    
    return 0;
}