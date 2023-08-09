package L337;

import java.util.HashMap;

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

    private HashMap<TreeNode, int[]> f;

    public int rob(TreeNode root) {
        f = new HashMap<TreeNode, int[]>();
        f.put(null, new int[] { 0, 0 });
        dfs(root);
        return Math.max(f.get(root)[0], f.get(root)[1]);
    }

    private void dfs(TreeNode root) {
        if (root == null)
            return;
        f.put(root, new int[2]);
        dfs(root.left);
        dfs(root.right);
        f.get(root)[0] = Math.max(f.get(root.left)[0], f.get(root.left)[1])
                + Math.max(f.get(root.right)[0], f.get(root.right)[1]);
        f.get(root)[1] = f.get(root.left)[0] + f.get(root.right)[0] + root.val;
    }
}
