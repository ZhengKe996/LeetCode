/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
 private:
  string s;
  int n;
  vector<string> ans;
  void dfs(int i) {
    if (i == 2 * n) {
      if (isValid(s)) ans.push_back(s);
      return;
    }
    s.push_back('(');
    dfs(i + 1);
    s.pop_back();

    s.push_back(')');
    dfs(i + 1);
    s.pop_back();
  }
  bool isValid(string &s) {
    int left = 0;
    for (char ch : s) {
      if (ch == '(')
        left++;
      else {
        if (left <= 0) return false;
        left--;
      }
    }

    return left == 0;
  }

  /**
   * 剪枝
   */
  void dfs2(int i, int left, int right) {
    if (left > n || right > n || !isValid2(s)) return;
    if (i == 2 * n) {
      ans.push_back(s);
      return;
    }
    s.push_back('(');
    dfs2(i + 1, left + 1, right);
    s.pop_back();

    s.push_back(')');
    dfs2(i + 1, left, right + 1);
    s.pop_back();
  }

  bool isValid2(string &s) {
    int left = 0;
    for (char ch : s) {
      if (ch == '(')
        left++;
      else {
        if (left <= 0) return false;
        left--;
      }
    }

    return true;
  }

 public:
  /**
   * 暴力递归
   */
  vector<string> generateParenthesis2(int n) {
    this->n = n;
    dfs(0);
    return ans;
  }

  /**
   * 剪枝优化
   */
  vector<string> generateParenthesis(int n) {
    this->n = n;
    dfs2(0, 0, 0);
    return ans;
  }
};
// @lc code=end
