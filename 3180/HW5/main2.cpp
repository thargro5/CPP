#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> queue1;
    queue<int> queue2;

public:

    void push(int x) {
        queue1.push(x);
    }

    int pop() {
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int top = queue1.front();
        queue1.pop();
        swap(queue1, queue2);//swaps the names so queue 1 always holds the stack
        return top;
    }

    int top() {
        while (queue1.size() > 1) { //pushes all the elements from queue1 into queue 2 except the last one 
            queue2.push(queue1.front());
            queue1.pop();
        }
        int top = queue1.front();
        queue2.push(queue1.front()); //after identifying the front push all elements back into queue 1 
        queue1.pop();
        swap(queue1, queue2);
        return top;
    }

    bool empty() {
        return queue1.empty() && queue2.empty();
    }
};



int main() {
    MyStack myStack;

    // Push elements onto the stack
    myStack.push(1);
    myStack.push(2);

    // Get and print the top element
    int topElement = myStack.top();
    cout << "Top element: " << topElement << endl;

    // Pop and print the top element
    int poppedElement = myStack.pop();
    cout << "Popped element: " << poppedElement << endl;

    // Check if the stack is empty
    bool isEmpty = myStack.empty();
    cout << "Is stack empty: " << (isEmpty ? "true" : "false") << endl;

    
    return 0;
}
