#include <iostream>
#include <stack>

using namespace std;

#define MAXSIZE 100

template <typename T>
class Deque {
private:
    T arr[MAXSIZE];
    int front;
    int back;

public:
    Deque() {
        front = -1;
        back = -1;
    }

    bool isEmpty() {
        return front == -1 && back == -1;
    }

    bool isFull() {
        return ((back + 1) % MAXSIZE) == front;
    }

    void clear() {
        front = -1;
        back = -1;
    }

    T Front() {
        if (isEmpty()) {
            cout << "Deque Empty!" << endl;
            return T();
        }
        return arr[front];
    }

    T Back() {
        if (isEmpty()) { 
            cout << "Deque Empty!" << endl;
            return T();
        }
        return arr[back];
    }

    void pushBack(T value) {
        if (isFull()) {
            cout << "Deque Full!" << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            back = 0;
        }
        else {
            back = (back + 1) % MAXSIZE;
        }
        arr[back] = value;
    }

    void pushFront(T value) {
        if (isFull()) {
            cout << "Deque Full!" << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            back = 0;
        }
        else if (front == 0) {
            front = MAXSIZE - 1;
        }
        else {
            front--;
        }
        arr[front] = value;
    }

    void popBack() {
        if (isEmpty()) {
            cout << "Deque Empty!" << endl;
            return;
        }

        if (back == front) {
            front = -1;
            back = -1;
        }
        else if (back == 0) {
            back = MAXSIZE - 1;
        }
        else {
            back--;
        }
    }

    void popFront() {
        if (isEmpty()) {
            cout << "Deque Empty!" << endl;
            return;
        }
        if (back == front) {
            front = -1;
            back = -1;
        }
        else {
            front = (front + 1) % MAXSIZE;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque Empty!" << endl;
            return;
        }

        int count = (back >= front) ? (back - front + 1) : (MAXSIZE - front + back + 1);

        for (int i = 0; i < count; i++) {
            T temp = Front();
            popFront();
            pushBack(temp);
            cout << temp << " ";
        }
        cout << endl;
    }

    void reverse() {
        if (isEmpty()) {
            cout << "Deque Empty!" << endl;
            return;
        }
        stack<T> tempStack;
        while (!isEmpty()) {
            tempStack.push(Front()); 
            popFront();
        }

        while (!tempStack.empty()) {
            pushBack(tempStack.top());
            tempStack.pop();
        }
    }
};
