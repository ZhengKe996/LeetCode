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
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr) return nullptr;

        if (root->val == key) {
            if (root->left == nullptr) return root->right;
            if (root->right == nullptr) return root->left;
            TreeNode *next = root->right;
            while (next->left != nullptr) next = next->left;
            root->right = deleteNode(root->right, next->val);
            root->val = next->val;
            return root;
        }

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};

int main() {
    return 0;
}
