package L297;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    private class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        List<String> ans = new ArrayList<String>();
        dfs(root, ans);
        return String.join(",", ans);
    }

    private void dfs(TreeNode node, List<String> ans) {
        if (node == null) {
            ans.add("null");
            return;
        }
        ans.add(Integer.toString(node.val));
        dfs(node.left, ans);
        dfs(node.right, ans);
    }

    // Decodes your encoded data to tree.
    private String[] ans;
    private int curr;

    public TreeNode deserialize(String data) {
        ans = data.split(",");
        curr = 0;
        return restore();
    }

    TreeNode restore() {
        if (ans[curr].equals("null")) {
            curr++;
            return null;
        }
        TreeNode root = new TreeNode(Integer.parseInt(ans[curr]));
        curr++;
        root.left = restore();
        root.right = restore();
        return root;
    }
}
