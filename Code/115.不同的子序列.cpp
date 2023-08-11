/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
 public:
  int numDistinct(string s, string t) {
    int n = s.length(), m = t.length();
    s = " " + s;
    t = " " + t;
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) f[i][0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        f[i][j] = f[i - 1][j];
        if (s[i] == t[j] && f[i][j] <= 2147483647 - f[i - 1][j - 1]) {
          f[i][j] += f[i - 1][j - 1];
        }
      }
    }
    return f[n][m];
  }
};
// @lc code=end
