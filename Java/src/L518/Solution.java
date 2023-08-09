package L518;

class Solution {
    public int change(int amount, int[] coins) {
        int n = coins.length;
        int[] newArr = new int[n + 1];
        newArr[0] = 0;
        for (int i = 0; i < coins.length; i++) {
            newArr[i + 1] = coins[i];
        }

        int[] f = new int[amount + 1];
        f[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = newArr[i]; j <= amount; j++) {
                f[j] += f[j - newArr[i]];
            }
        }
        return f[amount];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int amount = 5;
        int[] coins = { 1, 2, 5 };
        System.out.println(solution.change(amount, coins));
    }
}