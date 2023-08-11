/*
 * @lc app=leetcode.cn id=115 lang=java
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
  public int numDistinct(String s, String t) {
    int n = s.length(), m = t.length();
    s = " " + s;
    t = " " + t;

    int[][] f = new int[n + 1][m + 1];
    for (int i = 0; i < n; i++)
      f[i][0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        f[i][j] = f[i - 1][j];
        if (s.charAt(i) == t.charAt(j) && f[i][j] <= 2147483647 - f[i - 1][j - 1]) {
          f[i][j] += f[i - 1][j - 1];
        }
      }
    }
    return f[n][m];
  }
}
// @lc code=end
