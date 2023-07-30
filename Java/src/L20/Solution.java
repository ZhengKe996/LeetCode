package L20;

import java.util.Stack;

public class Solution {
    public boolean isValid(String s) {
        char[] chars = s.toCharArray();
        Stack<Character> stack = new Stack<>();
        for (char ch : chars) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stack.push(ch);
            } else {
                if (stack.empty()) return false;
                if (ch == ')' && stack.peek() != '(') return false;
                if (ch == ']' && stack.peek() != '[') return false;
                if (ch == '}' && stack.peek() != '{') return false;
                stack.pop();
            }
        }
        return stack.isEmpty();
    }
}
