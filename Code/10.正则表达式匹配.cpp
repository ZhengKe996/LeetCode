/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool isMatch(string s, string p) {
    int n = s.length(), m = p.length();
    s = " " + s;
    p = " " + p;

    vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
    f[0][0] = true;
    for (int j = 2; j <= m; j += 2) {
      if (p[j] == '*')
        f[0][j] = true;
      else
        break;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (p[j] >= 'a' && p[j] <= 'z') {
          f[i][j] = f[i - 1][j - 1] && s[i] == p[j];
        } else if (p[j] == '.') {
          f[i][j] = f[i - 1][j - 1];
        } else {
          f[i][j] = f[i][j - 2];
          if (s[i] == p[j - 1] || p[j - 1] == '.') {
            f[i][j] = f[i][j] || f[i - 1][j];
          }
        }
      }
    }

    return f[n][m];
  }
};
// @lc code=end
