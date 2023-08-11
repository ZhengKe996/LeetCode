/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int b = 131, n = haystack.length(), m = needle.length();

    vector<unsigned long long> H(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      H[i] = H[i - 1] * b + (haystack[i - 1] - 'a' + 1);
    }

    unsigned long long Hneedle = 0, powBM = 1;
    for (char ch : needle) {
      Hneedle = Hneedle * b + (ch - 'a' + 1);
      powBM = powBM * b;
    }
    for (int l = 1; l <= n - m + 1; l++) {
      int r = l + m - 1;
      if (H[r] - H[l - 1] * powBM == Hneedle &&
          haystack.substr(l - 1, m) == needle) {
        return l - 1;
      }
    }
    return -1;
  }
};
// @lc code=end
