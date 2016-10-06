/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.
*/



class MinStack {
    private:
        stack<int> elementStack;
        stack<int> minimumStack;
        int minElement = -1;
    public:
        void push(int x) {
            elementStack.push(x);
            if(elementStack.size() == 1 || x <= minElement) {
                minimumStack.push(x);
                minElement = x;
            } 
        }

        void pop() {
            if (elementStack.top() == minElement) {
                minimumStack.pop();
                if (!minimumStack.empty()) {
                    minElement = minimumStack.top();
                } else {
                    minElement = -1;
                }
            }
            elementStack.pop();
        }

        int top() {
            if (elementStack.empty()) return -1;
            return elementStack.top();
        }

        int getMin() {
            return minElement;
        }
};
Close
