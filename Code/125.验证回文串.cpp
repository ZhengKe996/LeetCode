/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

#include <iostream>
using namespace std;
// @lc code=start
class Solution {
 public:
  /**
   * 双指针法比较
   */
  bool isPalindrome1(string s) {
    /**
     * 1. 准备工作 处理字符串（大写转小写、移除非字母数字字符）
     */
    string t;
    for (char ch : s) {
      if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z')
        t.push_back(ch);
      else if (ch >= 'A' && ch <= 'Z')
        t.push_back(ch - 'A' + 'a');
    }

    // 2. 双指针进行比较
    int l = 0, r = t.size() - 1;
    while (l < r) {
      if (t[l] != t[r]) return false;
      l++;
      r--;
    }
    return true;
  }

  bool isPalindrome(string s) {
    int l = getNext(s, 0);
    int r = getPre(s, s.size() - 1);
    while (l < r) {
      if (!equalsIgnoreCase(s[l], s[r])) return false;
      l = getNext(s, l + 1);
      r = getPre(s, r - 1);
    }
    return true;
  }

 private:
  bool isDigitorLetter(char ch) {
    return ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' ||
           ch >= 'A' && ch <= 'Z';
  }

  int getNext(string& s, int i) {
    while (i < s.size() && !isDigitorLetter(s[i])) i++;
    return i;
  }

  int getPre(string& s, int i) {
    while (i >= 0 && !isDigitorLetter(s[i])) i--;
    return i;
  }

  int equalsIgnoreCase(char ch1, char ch2) {
    if (ch1 >= 'A' && ch1 <= 'Z') ch1 = ch1 - 'A' + 'a';
    if (ch2 >= 'A' && ch2 <= 'Z') ch2 = ch2 - 'A' + 'a';
    return ch1 == ch2;
  }
};
// @lc code=end
