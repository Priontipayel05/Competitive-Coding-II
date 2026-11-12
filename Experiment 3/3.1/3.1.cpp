
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> input;
    stack<int> output;

    void shiftStacks() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        input.push(x);
    }

    int pop() {
        shiftStacks();
        if (output.empty()) return -1;

        int element = output.top();
        output.pop();
        return element;
    }

    int peek() {
        shiftStacks();
        if (output.empty()) return -1;

        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl;
    cout << "Removed element: " << q.pop() << endl;
    cout << "Front element: " << q.peek() << endl;
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
