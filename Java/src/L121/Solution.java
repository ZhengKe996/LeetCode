package L121;

public class Solution {
    public int maxProfit(int[] prices) {
        // 0.Move index to 1-based
        int n = prices.length;
        int k = 1;
        int[] newArr = new int[n + 1];
        newArr[0] = 0;
        for (int i = 0; i < prices.length; i++) {
            newArr[i + 1] = prices[i];
        }

        // 1.Define f, initialize 负无穷
        int[][][] f = new int[n + 1][2][k + 1];
        for (int i = 0; i < f.length; i++) {

            for (int j = 0; j < k + 1; j++) {
                f[i][0][j] = (int) -1e9;
                f[i][1][j] = (int) -1e9;
            }
        }
        f[0][0][0] = 0; // 合法起点

        // 2. Loop over all states;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int p = 0; p <= k; p++) {
                    // 3. Copy decisions 抄决策方程
                    if (p > 0)
                        f[i][1][p] = Math.max(f[i][1][p], f[i - 1][0][p - 1] - newArr[i]);
                    f[i][0][p] = Math.max(f[i][0][p], f[i - 1][1][p] + newArr[i]);
                    f[i][j][p] = Math.max(f[i][j][p], f[i - 1][j][p]);
                }
            }
        }

        // 4. Return target
        int ans = (int) -1e9;
        for (int i = 0; i <= k; i++) {
            ans = Math.max(ans, f[n][0][i]);
        }
        return ans;

    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] prices = { 7, 1, 5, 3, 6, 4 };
        System.out.println(solution.maxProfit(prices));
    }
}
