#include<iostream>
#include<stack>
using namespace std;

// Implement a stack with push, pop, top, findMin in O(1) time and space complexity:
// Brute force: 
/**
 * 1. We can use a stack to store the elements and another stack to store the minimum elements.
 * Time complexity: O(1)
 * Space complexity: O(n)
*/
class MinStackBF {
    stack<int> s;
    stack<int> minStack;
public:
    void push(int x) {
        s.push(x);
        if(minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }
    void pop() {
        if(s.top() == minStack.top()) {
            minStack.pop();
        }
        s.pop();
    }
    int top() {
        return s.top();
    }
    int getMin() {
        return minStack.top();
    }
};

// Optimized approach:
/**
 * 1. create a variable minElement to store the minimum element.
 * 2. We can use a single stack to store the elements in (y = x - minElement) format.
 * 3. If y is negative, then we need to update the minElement to x and push y to the stack.
 * 4. If y is positive, then we can directly push y to the stack.
 * 5. While popping, if the top element is negative, that means the minimum element is being popped, so we need to update the minElement. in this case, we need to pop the top element and update the minElement to (minElement - topElement). and here the original element can be obtained by minElement.
 * 6. if the top element is positive, then we can directly pop the top element. and here the original element can be obtained by (topElement + minElement).
 * Time complexity: O(1)
 * Space complexity: O(1)
*/
class MinStack {
    stack<int> s;
    int minElement;
public:
    MinStack() {
        minElement = INT_MAX;
    }
    void push(int x) {
        if(s.empty()) {
            s.push(0);
            minElement = x;
        } else {
            s.push(x - minElement);
            if(x < minElement) {
                minElement = x;
            }
        }
    }
    void pop() {
        if(s.empty()) {
            return;
        }
        int topElement = s.top();
        s.pop();
        if(topElement < 0) {
            minElement = minElement - topElement;
        }
    }
    int top() {
        int topElement = s.top();
        if(topElement < 0) {
            return minElement;
        } else {
            return topElement + minElement;
        }
    }
    int getMin() {
        return minElement;
    }
};

int main() {
    MinStack minStack;
    minStack.push(3);
    minStack.push(5);
    cout << minStack.getMin() << endl;
    minStack.push(2);
    minStack.push(1);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    return 0;
}