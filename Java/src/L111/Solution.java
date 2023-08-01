package L111;

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

    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        int left = minDepth(root.left);
        int right = minDepth(root.right);
        return (left == 0 || right == 0) ? left + right + 1 : Math.min(left, right) + 1;
    }


    /**
     * 这样必超时。。。。。
     *
     * @param root
     * @return
     */
    public int minDept2(TreeNode root) {
        if (root == null) return 0;
        return (minDepth(root.left) == 0 || minDepth(root.right) == 0)
                ? minDepth(root.left) + minDepth(root.right) + 1
                : Math.min(minDepth(root.left), minDepth(root.right)) + 1;
    }

}
