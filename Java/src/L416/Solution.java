package L416;

public class Solution {
    public boolean canPartition(int[] nums) {
        int n = nums.length;
        int[] newArr = new int[n + 1];
        newArr[0] = 0;

        for (int i = 0; i < nums.length; i++) {
            newArr[i + 1] = nums[i];
        }

        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += newArr[i];
        if (sum % 2 == 1)
            return false;

        boolean[] f = new boolean[sum / 2 + 1];
        f[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = sum / 2; j >= newArr[i]; j--) {
                f[j] |= f[j - newArr[i]];
            }
        }
        return f[sum / 2];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = { 1, 5, 11, 5 };
        System.out.println(solution.canPartition(nums));
    }
}
