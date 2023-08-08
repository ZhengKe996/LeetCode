package L122;

public class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0;
        for (int i = 1; i < prices.length; i++) {
            ans += Math.max(prices[i] - prices[i - 1], 0);
        }
        return ans;
    }

    public int maxProfit2(int[] prices) {
        // 0.Move index to 1-based
        int n = prices.length;
        int[] newArr = new int[n + 1];
        newArr[0] = 0;
        for (int i = 0; i < prices.length; i++) {
            newArr[i + 1] = prices[i];
        }

        // 1.Define f, initialize 负无穷
        int[][] f = new int[n + 1][2];
        for (int i = 0; i < f.length; i++) {
            f[i][0] = (int) -1e9;
            f[i][1] = (int) -1e9;
        }
        f[0][0] = 0; // 合法起点

        // 2. Loop over all states;
        for (int i = 1; i <= n; i++) {
            // 3. Copy decisions 抄决策方程
            f[i][1] = Math.max(f[i][1], f[i - 1][0] - newArr[i]);
            f[i][0] = Math.max(f[i][0], f[i - 1][1] + newArr[i]);
            for (int j = 0; j < 2; j++) {
                f[i][j] = Math.max(f[i][j], f[i - 1][j]);
            }
        }

        // 4. Return target
        return f[n][0];
    }

    public static void main(String[] args) {

        Solution solution = new Solution();
        int[] prices = { 7, 1, 5, 3, 6, 4 };
        int ans = solution.maxProfit(prices);
        int ans2 = solution.maxProfit2(prices);
        System.out.println(ans + " " + ans2);

    }
}
