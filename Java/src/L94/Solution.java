package L94;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    private class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    private List<Integer> ans = new ArrayList<>();

    public List<Integer> inorderTraversal(TreeNode root) {
       ans = new ArrayList<Integer>();
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode node) {
        if (node == null) return;
        dfs(node.left);
        ans.add(node.val);
        dfs(node.right);

    }
}
