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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        return build(0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    vector<int> preorder, inorder;

    TreeNode *build(int l1, int r1, int l2, int r2) {
        if (l1 > r1) return nullptr;


        TreeNode *root = new TreeNode(preorder[l1]);
        int mid = l2;// mid 是root在inorder中的位置;
        while (inorder[mid] != root->val) {
            mid++;
        }

        root->left = build(l1 + 1, l1 + (mid - l2), l2, mid - 1);
        root->right = build(l1 + (mid - l2) + 1, r1, mid + 1, r2);
        return root;
    }
};

int main() {
    return 0;
}
