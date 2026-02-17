#include <iostream>
#include <stack>

using namespace std;

#define MAXSIZE 100

template <typename T>
class Queue {
private:
    int front, back;
    T arr[MAXSIZE];

public:
    Queue() {
        front = -1;
        back = -1;
    }

    bool isEmpty() {
        return front == -1 && back == -1;
    }

    bool isFull() {
        return ((back + 1) % MAXSIZE) == front;
    }

    T Front() {
        if (isEmpty()) {
            cout << "Queue Empty!" << endl;
            return T();
        }
        return arr[front];
    }

    T Back() {
        if (isEmpty()) {
            cout << "Queue Empty!" << endl;
            return T();
        }
        return arr[back];
    }

    void clear() {
        front = -1;
        back = -1;
    }

    void enqueue(T value) {
        if (isFull()) {
            cout << "Queue Full!" << endl;
        }
        else {
            if (isEmpty()) {
                front = 0;
                back = 0;
            }
            else {
                back = (back + 1) % MAXSIZE;
            }
            arr[back] = value;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty!" << endl;
        }
        else {
            if (front == back) {
                front = -1;
                back = -1;
            }
            else {
                front = (front + 1) % MAXSIZE;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Empty!" << endl;
            return;
        }

        int count;
        if (back >= front) {
            count = back - front + 1;
        }
        else {
            count = MAXSIZE - front + back + 1;
        }

        for (int i = 0; i < count; i++) {
            T temp = Front();
            dequeue();
            enqueue(temp);
            cout << temp << " ";
        }
        cout << endl;
    }

    void reverse() {
        if (isEmpty()) {
            cout << "Queue Empty!" << endl;
            return;
        }
        stack<T> tempStack;

        while (!isEmpty()) {
            tempStack.push(Front());
            dequeue();
        }

        while (!tempStack.empty()) {
            enqueue(tempStack.top());
            tempStack.pop();
        }
    }
};

