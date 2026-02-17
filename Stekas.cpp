#include <iostream>

using namespace std;


#define MAXSIZE 100

template <typename T>
class Stekas {
private:
    int top;
    T array[MAXSIZE];

public:
    Stekas() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAXSIZE - 1;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stekas pilnas!" << endl;
        }
        else {
            top++;
            array[top] = value;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stekas tuscias!" << endl;
        }
        else {
            top--;
        }
    }

    T peek() {
        if (isEmpty()) {
            cout << "Stekas tuscias!" << endl;
            
            return T();
        }
        else {
            return array[top];
        }
    }

    void clear() {
        top = -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stekas tuscias" << endl;
        }
        else {
            Stekas<T> temp;
            T value;

            while (!isEmpty()) {
                value = peek();
                temp.push(value);
                pop();
            }

            
            while (!temp.isEmpty()) {
                value = temp.peek();
                cout << value << " ";
                push(value);
                temp.pop();
            }
            cout << endl;
        }
    }
};

