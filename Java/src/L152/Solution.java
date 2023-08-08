package L152;

public class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int[] fmax = new int[n], fmin = new int[n];
        fmax[0] = nums[0];
        fmin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            fmax[i] = Math.max(Math.max(fmax[i - 1] * nums[i], fmin[i - 1] * nums[i]), nums[i]);
            fmin[i] = Math.min(Math.min(fmax[i - 1] * nums[i], fmin[i - 1] * nums[i]), nums[i]);
        }
        int ans = fmax[0];
        for (int i = 1; i < n; i++) {
            ans = Math.max(ans, fmax[i]);
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = { 2, 3, -2, 4 };
        int ans = solution.maxProduct(nums);
        System.out.println(ans);

    }
}
