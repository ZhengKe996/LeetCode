#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> preorder(Node *root) {
        if (root == nullptr) return ans;
        stack<Node *> stack;
        stack.push(root);
        while (!stack.empty()) {
            Node *node = stack.top();
            stack.pop();
            ans.push_back(node->val);
            for (int i = node->children.size() - 1; i >= 0; i--) {
                stack.push(node->children[i]);
            }
        }
        return ans;
    }

private:
    vector<int> ans;
};

int main() {
    return 0;
}
