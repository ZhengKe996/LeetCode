#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return check(root, LONG_MIN, LONG_MAX);
    }

private:
    bool check(TreeNode *root,  long long rangeLeft,  long long rangeRight) {
        if (root == nullptr) return true;
        if (root->val < rangeLeft || root->val > rangeRight) return false;
        return check(root->left, rangeLeft, (long) root->val - 1) &&
               check(root->right, (long) root->val + 1, rangeRight);
    }
};

int main() {
    return 0;
}
