/*
 * @lc app=leetcode.cn id=680 lang=java
 *
 * [680] 验证回文串 II
 */

// @lc code=start
class Solution {
  public boolean validPalindrome(String s) {
    return check(s, 0, s.length() - 1, 1);

  }

  /**
   * 将原问题转为递归
   * 
   * @param s     输入的字符串
   * @param l     左下标
   * @param r     右下表
   * @param times 能删的次数 默认1
   * @return
   */
  private boolean check(String s, int l, int r, int times) {
    while (l < r) {
      if (s.charAt(l) != s.charAt(r)) {
        // 判断删除掉一个字符（要么删左 要么删右）能否成为回文
        return times > 0 && (check(s, l + 1, r, 0) || check(s, l, r - 1, 0));
      }
      l++;
      r--;
    }
    return true;
  }
}
// @lc code=end
