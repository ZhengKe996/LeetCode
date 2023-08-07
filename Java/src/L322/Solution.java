package L322;

import java.util.Arrays;

class Solution {
    public int coinChange(int[] coins, int amount) {
        int max = amount + 1;
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (coins[j] <= i) {
                    dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }

    /**
     * 动态规划
     * 
     * @param coins
     * @param amount
     * @return
     */
    public int coinChange2(int[] coins, int amount) {
        int INF = (int) 1e9;
        int[] opt = new int[amount + 1];
        opt[0] = 0;
        for (int i = 1; i <= amount; i++) {
            opt[i] = INF;
            for (int j = 0; j < coins.length; j++) {
                if (i - coins[j] >= 0)
                    opt[i] = Math.min(opt[i], opt[i - coins[j]] + 1);
            }
        }
        if (opt[amount] >= INF)
            opt[amount] = -1;
        return opt[amount];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] coins = { 1, 2, 5 };
        int amount = 11;
        int ans = solution.coinChange(coins, amount);
        int ans2 = solution.coinChange2(coins, amount);
        System.out.println(ans + " " + ans2);
    }
}