package L150;

import java.util.Stack;

public class Solution {
    private static Stack<Integer> stack = new Stack<>();

    public static int evalRPN(String[] tokens) {
        for (String s : tokens) {
            if (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")) {
                int y = stack.peek();
                stack.pop();
                int x = stack.peek();
                stack.pop();
                int z = calc(x, y, s);
                stack.push(z);
            } else {
                stack.push(Integer.parseInt(s));
            }

        }
        return stack.peek();
    }

    private static int calc(int x, int y, String op) {
        if (op.equals("+")) return x + y;
        if (op.equals("-")) return x - y;
        if (op.equals("*")) return x * y;
        if (op.equals("/")) return x / y;
        return 0;
    }

    public static void main(String[] args) {
//        String[] token = {"2", "1", "+", "3", "*"};
        String[] token = {"4", "13", "5", "/", "+"};
        int i = evalRPN(token);
        System.out.println(i);
    }
}
