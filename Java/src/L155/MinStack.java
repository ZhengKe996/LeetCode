package L155;

import java.util.Stack;

public class MinStack {
    public MinStack() {

    }

    private Stack<Integer> s = new Stack<>();
    private Stack<Integer> preMin= new Stack<>();

    public void push(int val) {
        s.push(val);
        if (preMin.isEmpty()) {
            preMin.push(val);
        } else {
            preMin.push(Math.min(preMin.peek(), val));
        }
    }

    public void pop() {
        s.pop();
        preMin.pop();
    }

    public int top() {
        return s.peek();
    }

    public int getMin() {
        return preMin.peek();
    }
}
