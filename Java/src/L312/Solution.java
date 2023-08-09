package L312;

public class Solution {
    int[] nums1;
    int[][] f;

    /**
     * 记忆化搜索
     * 
     * @param nums
     * @return
     */
    public int maxCoins(int[] nums) {
        int n = nums.length;
        nums1 = new int[n + 2];
        for (int i = 1; i <= n; i++)
            nums1[i] = nums[i - 1];

        nums1[0] = 1;
        nums1[n + 1] = 1;
        f = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = -1;
            }
        }

        return calc(1, n);
    }

    private int calc(int l, int r) {
        if (l > r)
            return 0;
        if (f[l][r] != -1)
            return f[l][r];
        for (int i = l; i <= r; i++) {
            f[l][r] = Math.max(f[l][r], calc(l, i - 1) + calc(i + 1, r) + nums1[i] * nums1[l - 1] * nums1[r + 1]);
        }
        return f[l][r];
    }

    public int maxCoins2(int[] nums) {
        int n = nums.length;
        int[] newArr = new int[n + 2];
        newArr[0] = 1;
        for (int i = 0; i < n; i++) {
            newArr[i + 1] = nums[i];
        }
        newArr[newArr.length - 1] = 1;

        int[][] f = new int[n + 2][n + 2];
        for (int len = 1; len <= n; len++) {
            for (int l = 1; l <= n - len + 1; l++) {
                int r = l + len - 1;
                for (int p = l; p <= r; p++) {
                    f[l][r] = Math.max(f[l][r], f[l][p - 1] + f[p + 1][r] +
                            newArr[p] * newArr[l - 1] * newArr[r + 1]);
                }
            }
        }
        return f[1][n];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = { 3, 1, 5, 8 };
        System.out.println(solution.maxCoins(nums));
        System.out.println(solution.maxCoins2(nums));
    }
}
