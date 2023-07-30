#include <iostream>
#include <stack>

using namespace std;

/**
 * 使用两个栈来维护一个最小栈。 其中一个栈存放最小值
 */
class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        s.push(val);
        if (preMin.empty()) {
            preMin.push(val);
        } else {
            preMin.push((min(preMin.top(), val)));
        }
    }

    void pop() {
        s.pop();
        preMin.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return preMin.top();
    }

private:
    stack<int> s;
    stack<int> preMin;
};

int main() {
    return 0;
}
