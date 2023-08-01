package L46;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    private boolean[] used;
    private List<Integer> a = new ArrayList<>();
    int n;
    private List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> permute(int[] nums) {
        this.n = nums.length;
        this.used = new boolean[n];
        recur(nums, 0);
        return ans;
    }

    private void recur(int[] nums, int pos) {
        if (pos == n) {
            ans.add(new ArrayList<Integer>(a));
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                a.add(nums[i]);
                used[i] = true;
                recur(nums, pos + 1);
                used[i] = false;
                a.remove(a.size() - 1);
            }
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {1, 2, 3};
        List<List<Integer>> list = s.permute(nums);
        for (int i = 0; i < list.size(); i++) {
            for (int j = 0; j < list.get(i).size(); j++) {
                System.out.print(list.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }
}
