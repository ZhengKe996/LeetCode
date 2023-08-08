package L309;

public class Solution {
    public int maxProfit(int[] prices) {
        // 0.Move index to 1-based
        int n = prices.length;
        int[] newArr = new int[n + 1];
        newArr[0] = 0;
        for (int i = 0; i < prices.length; i++) {
            newArr[i + 1] = prices[i];
        }

        // 1.Define f, initialize 负无穷
        int[][][] f = new int[n + 1][2][2];
        for (int i = 0; i < f.length; i++) {
            f[i][0][0] = (int) -1e9;
            f[i][0][1] = (int) -1e9;
            f[i][1][0] = (int) -1e9;
            f[i][1][1] = (int) -1e9;
        }
        f[0][0][0] = 0; // 合法起点

        // 2. Loop over all states;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int l = 0; l < 2; l++) {
                    // 3. Copy decisions 抄决策方程
                    // 3. Copy decisions 抄决策方程
                    if (l == 0)
                        f[i][1][0] = Math.max(f[i][1][0], f[i - 1][0][0] - newArr[i]);

                    // 卖出股票会冷冻
                    f[i][0][1] = Math.max(f[i][0][1], f[i - 1][1][0] + newArr[i]);
                    f[i][j][0] = Math.max(f[i][j][0], f[i - 1][j][l]);
                }
            }
        }

        // 4. Return target
        return Math.max(f[n][0][1], f[n][0][0]);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] prices = { 1, 2, 3, 0, 2 };
        System.out.println(solution.maxProfit(prices));
    }
}
