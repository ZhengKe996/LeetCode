package L1000;

public class Solution {
    public int mergeStones(int[] stones, int k) {
        int n = stones.length;

        int[][][] f = new int[n][n][k + 1];
        for (int i = 0; i < f.length; i++) {
            for (int j = 0; j < f[i].length; j++) {
                for (int j2 = 0; j2 < f[i][j].length; j2++) {
                    f[i][j][j2] = (int) 1e9;
                }
            }
        }
        for (int l = 0; l < n; l++)
            f[l][l][1] = 0;
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l < n - len + 1; l++) {
                int r = l + len - 1;
                for (int i = 2; i <= k; i++) {
                    for (int p = l; p < r; p++) {
                        f[l][r][i] = Math.min(f[l][r][i], f[l][p][1] + f[p + 1][r][i - 1]);
                    }
                }
                int sum = 0;
                for (int p = l; p <= r; p++)
                    sum += stones[p];
                f[l][r][1] = Math.min(f[l][r][1], f[l][r][k] + sum);
            }
        }
        return f[0][n - 1][1] == 1e9 ? -1 : f[0][n - 1][1];
    }

    public static void main(String[] args) {

        Solution solution = new Solution();
        int[] stones = { 3, 2, 4, 1 };
        int k = 2;
        System.out.println(solution.mergeStones(stones, k));
    }
}
