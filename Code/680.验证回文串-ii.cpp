/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool validPalindrome(string s) { return check(s, 0, s.size() - 1, 1); }

 private:
  bool check(string& s, int l, int r, int times) {
    while (l < r) {
      if (s[l] != s[r]) {
        // 判断删除掉一个字符（要么删左 要么删右）能否成为回文
        return times > 0 && (check(s, l + 1, r, 0) || check(s, l, r - 1, 0));
      }
      l++;
      r--;
    }
    return true;
  }
};
// @lc code=end
