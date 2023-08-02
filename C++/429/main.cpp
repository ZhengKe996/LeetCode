#include <iostream>
#include <queue>

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
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<Node *> queue;
        queue.push(root);

        while (!queue.empty()) {
            int cnt = queue.size();
            vector<int> level;
            for (int i = 0; i < cnt; ++i) {
                Node *cur = queue.front();
                queue.pop();
                level.push_back(cur->val);
                for (Node *child: cur->children) {
                    queue.push(child);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};

int main() {
    return 0;
}
