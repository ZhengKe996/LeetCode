package L122;

public class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0;
        for (int i = 1; i < prices.length; i++) {
            ans += Math.max(prices[i] - prices[i - 1], 0);
        }
        return ans;
    }

    public static void main(String[] args) {

        Solution solution = new Solution();
        int[] prices = { 7, 1, 5, 3, 6, 4 };
        int ans = solution.maxProfit(prices);
        System.out.println(ans);

    }
}
