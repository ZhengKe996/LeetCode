package L78;

import java.util.ArrayList;
import java.util.List;

public class Solution {

    static int n = 0;
    static List<Integer> chosen = new ArrayList<Integer>();
    static List<List<Integer>> ans = new ArrayList<List<Integer>>();

    public static List<List<Integer>> subsets(int[] nums) {
        n = nums.length;
        dfs(0, nums);
        return ans;
    }

    public static void dfs(int cur, int[] nums) {
        if (cur == n) {
            ans.add(new ArrayList<Integer>(chosen));
            return;
        }
        chosen.add(nums[cur]);
        dfs(cur + 1, nums);
        chosen.remove(chosen.size() - 1);
        dfs(cur + 1, nums);
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3};
        List<List<Integer>> list = subsets(nums);
        for (int i = 0; i < list.size(); i++) {
            for (int j = 0; j < list.get(i).size(); j++) {
                System.out.print(list.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }
}
