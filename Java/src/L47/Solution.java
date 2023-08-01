package L47;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    private boolean[] vis;

    private void backtrack(int[] nums, List<List<Integer>> ans, int idx, List<Integer> perm) {
        if (idx == nums.length) {
            ans.add(new ArrayList<>(perm));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }

            perm.add(nums[i]);
            vis[i] = true;
            backtrack(nums, ans, idx + 1, perm);
            vis[i] = false;
            perm.remove(idx);
        }
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> perm = new ArrayList<>();
        vis = new boolean[nums.length];
        Arrays.sort(nums);
        backtrack(nums, ans, 0, perm);
        return ans;
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 1, 2};
        int[] nums2 = {1, 2, 3};
        Solution solution = new Solution();
        List<List<Integer>> ans1 = solution.permuteUnique(nums1);
        List<List<Integer>> ans2 = solution.permuteUnique(nums2);
        for (int i = 0; i < ans1.size(); i++) {
            for (int j = 0; j < ans1.get(i).size(); j++) {
                System.out.print(ans1.get(i).get(j) + " ");
            }
            System.out.println();
        }

        System.out.println("----------------------------");

        for (int i = 0; i < ans2.size(); i++) {
            for (int j = 0; j < ans2.get(i).size(); j++) {
                System.out.print(ans2.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }
}
