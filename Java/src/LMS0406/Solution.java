package LMS0406;

public class Solution {
    private class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        return getNext(root, p.val);
    }

    public TreeNode inorderSuccessor2(TreeNode root, TreeNode p) {
        if (root == null || p == null) return null;
        if (root.val <= p.val) {
            return inorderSuccessor2(root.right, p);
        } else {
            TreeNode left = inorderSuccessor2(root.left, p);
            return left == null ? root : left;
        }
    }

    private TreeNode getNext(TreeNode node, int val) {
        TreeNode ans = null;
        TreeNode curr = node;
        while (curr != null) {
            if (curr.val == val) {
                if (curr.right != null) {
                    ans = curr.right;
                    while (ans.left != null) ans = ans.left;
                }
                break;
            }
            if (val < curr.val) {
                if (ans == null || ans.val > curr.val) ans = curr;
                curr = curr.left;
            } else {
                curr = curr.right;
            }
        }
        return ans;
    }
}
