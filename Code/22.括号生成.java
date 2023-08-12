/*
 * @lc app=leetcode.cn id=22 lang=java
 *
 * [22] 括号生成
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
  StringBuffer s = new StringBuffer();
  int n = 0;
  List<String> ans = new ArrayList<>();;

  public List<String> generateParenthesis(int n) {
    this.n = n;
    dfs(0, 0, 0);
    return ans;
  }

  private void dfs(int i, int left, int right) {
    if (left > n || right > n || !isValid(s.toString()))
      return;
    if (i == 2 * n) {
      ans.add(s.toString());
      return;
    }
    s.append('(');
    dfs(i + 1, left + 1, right);

    s.deleteCharAt(s.length() - 1);

    s.append(')');
    dfs(i + 1, left, right + 1);
    s.deleteCharAt(s.length() - 1);
  }

  private boolean isValid(String s) {
    int left = 0;
    for (char ch : s.toCharArray()) {
      if (ch == '(')
        left++;
      else {
        if (left <= 0)
          return false;
        left--;
      }
    }
    return true;
  }
}
// @lc code=end
