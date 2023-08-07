package L53;

public class Solution {
    /**
     * 前缀和
     *
     * @param nums
     * @return
     */
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int[] s = new int[n + 1];
        int[] preMin = new int[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        preMin[0] = s[0];
        for (int i = 1; i <= n; i++) {
            preMin[i] = Math.min(preMin[i - 1], s[i]);
        }
        int ans = -1000000;
        for (int i = 1; i <= n; i++) {
            ans = Math.max(ans, s[i] - preMin[i - 1]);
        }
        return ans;
    }

    public int maxSubArray2(int[] nums) {
        int n = nums.length;
        int[] f = new int[n];
        f[0] = nums[0];
        for (int i = 1; i < n; i++) {
            f[i] = Math.max(f[i - 1] + nums[i], nums[i]);
        }
        int ans = f[0];
        for (int i = 1; i < n; i++) {
            ans = Math.max(ans, f[i]);
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        int i = solution.maxSubArray(nums);
        int i2 = solution.maxSubArray2(nums);
        System.out.println(i + " " + i2);
    }
}
