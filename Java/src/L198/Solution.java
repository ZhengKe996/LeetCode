package L198;

public class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        int[] newArr = new int[n + 1];
        newArr[0] = 0;
        for (int i = 0; i < nums.length; i++) {
            newArr[i + 1] = nums[i];
        }

        int[][] f = new int[n + 1][2];
        for (int i = 0; i < f.length; i++) {
            f[i][0] = (int) -1e9;
            f[i][1] = (int) -1e9;
        }

        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                f[i][0] = Math.max(f[i - 1][0], f[i - 1][1]);
                f[i][1] = f[i - 1][0] + newArr[i];
            }
        }

        return Math.max(f[n][0], f[n][1]);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = { 1, 2, 3, 1 };
        System.out.println(solution.rob(nums));
    }
}
