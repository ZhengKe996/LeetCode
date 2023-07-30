#include <iostream>
#include <stack>
#include <string>

using namespace std;


class Solution {
public:
    int calculate(string s) {
        s += " ";
        vector<string> tokens;
        string number = "";
        bool needsZero = true; // 是否要补0
        for (char ch: s) {
            if (ch >= '0' && ch <= '9') {
                number += ch;
                needsZero = false;
                continue;
            } else {
                if (!number.empty()) {
                    tokens.push_back(number);
                    number = ""; // 清空number
                }
            }

            // 遇到空格跳
            if (ch == ' ') {
                continue;
            }

            // 如果是左括号 压栈
            if (ch == '(') {
                ops.push(ch);
                needsZero = true;
                continue;
            }

            // 处理右括号，如果栈顶不是左括号则可以一直算
            if (ch == ')') {
                while (ops.top() != '(') {
                    tokens.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.pop();
                needsZero = false;
                continue;
            }

            // 处理负数; 补0
            if ((ch == '+' || ch == '-') && needsZero) {
                tokens.push_back("0");
            }

            int currRank = getRank(ch);

            while (!ops.empty() && getRank(ops.top()) >= currRank) { // 栈顶的优先级高
                tokens.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(ch); // 当前符号入栈
            needsZero = true;
        }

        while (!ops.empty()) {
            tokens.push_back(string(1, ops.top())); // 构造一个包含1个字符的字符串
            ops.pop();
        }
        return evalRPN(tokens);
    }

private:
    stack<char> ops;
    stack<int> s;


    int getRank(char ch) {
        if (ch == '*' || ch == '/') return 2;
        if (ch == '+' || ch == '-') return 1;
        return 0;
    }

    int calc(long long x, long long y, string &op) {
        if (op == "+") return x + y;
        if (op == "-") return x - y;
        if (op == "*") return x * y;
        if (op == "/") return x / y;

        return 0;
    }

    int evalRPN(vector<string> &tokens) {
        for (string &token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();

                int z = calc(x, y, token);
                s.push(z);
            } else {
                s.push(atoi(token.c_str()));
            }
        }
        return s.top();
    }
};

int main() {
    Solution s;
    cout << s.calculate("(1+(4+5+2)-3)+(6+8)");
    return 0;
}