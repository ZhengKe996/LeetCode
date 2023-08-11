/*
 * @lc app=leetcode.cn id=10 lang=java
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
  public boolean isMatch(String s, String p) {
    int n = s.length(), m = p.length();
    s = " " + s;
    p = " " + p;

    boolean[][] f = new boolean[n + 1][m + 1];
    f[0][0] = true;
    for (int j = 2; j <= m; j += 2) {
      if (p.charAt(j) == '*')
        f[0][j] = true;
      else
        break;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (p.charAt(j) >= 'a' && p.charAt(j) <= 'z') {
          f[i][j] = f[i - 1][j - 1] && s.charAt(i) == p.charAt(j);
        } else if (p.charAt(j) == '.') {
          f[i][j] = f[i - 1][j - 1];
        } else {
          f[i][j] = f[i][j - 2];
          if (s.charAt(i) == p.charAt(j - 1) || p.charAt(j - 1) == '.') {
            f[i][j] = f[i][j] || f[i - 1][j];
          }
        }
      }
    }

    return f[n][m];
  }
}
// @lc code=end
