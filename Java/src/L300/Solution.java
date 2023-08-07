package L300;

public class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int f[] = new int[n];
        for (int i = 0; i < n; i++)
            f[i] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    f[i] = Math.max(f[i], f[j] + 1);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, f[i]);

        }
        return ans;
    }

    public int lengthOfLIS2(int[] nums) {
        int n = nums.length;
        int f[] = new int[n];
        int pre[] = new int[n];
        for (int i = 0; i < n; i++) {
            f[i] = 1;
            pre[i] = -1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    f[i] = Math.max(f[i], f[j] + 1);
                    pre[i] = j;
                }
            }
        }
        int ans = 0;
        int end = -1;
        for (int i = 0; i < n; i++) {
            if (f[i] > ans) {
                ans = f[i];
                end = i;
            }

        }
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
        int ans = solution.lengthOfLIS(nums);
        int ans2 = solution.lengthOfLIS2(nums);
        System.out.println(ans + " " + ans2);
    }
}
