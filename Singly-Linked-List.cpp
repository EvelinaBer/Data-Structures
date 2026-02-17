#include <iostream>

using namespace std;

template <typename T>
struct node {
    T data;
    node<T>* next;
    node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class linkedList {
private:
    node<T>* head;
    node<T>* tail;

public:
    linkedList() : head(nullptr), tail(nullptr) {}

    ~linkedList() {
        clear();
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void addNodeEnd(T value) {
        node<T>* temp = new node<T>(value);
        if (isEmpty()) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    void addNodeFront(T value) {
        node<T>* temp = new node<T>(value);
        if (isEmpty()) {
            head = temp;
            tail = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }
    }

    void addNodePosition(T value, int position) {
        if (position == 0) {
            addNodeFront(value);
            return;
        }

        node<T>* current = head;
        for (int i = 0; current != nullptr && i < position - 1; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Wrong Position!" << endl;
            return;
        }

        node<T>* temp = new node<T>(value);
        temp->next = current->next;
        current->next = temp;

        if (temp->next == nullptr) {
            tail = temp;
        }
    }

    void deleteNodeFront() {
        if (isEmpty()) return;
        node<T>* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) tail = nullptr;
    }

    void deleteNodeEnd() {
        if (isEmpty()) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        node<T>* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    void display() {
        node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void clear() {
        node<T>* current = head;
        while (current != nullptr) {
            node<T>* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
    }

    void reverse() {
        if (isEmpty()) return;
        node<T>* prev = nullptr, * current = head, * next = nullptr;
        tail = head;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

