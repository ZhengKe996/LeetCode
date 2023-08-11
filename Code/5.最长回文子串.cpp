/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
 private:
  vector<long long> preH;
  vector<long long> sufH;
  vector<long long> powB;
  const int b = 131, p = 1e9 + 7;

  long long calcHash(int l, int r) {
    return ((preH[r + 1] - preH[l] * powB[r - l + 1]) % p + p) % p;
  }

  long long calcReverseHash(int l, int r) {
    return ((sufH[l + 1] - sufH[r + 2] * powB[r - l + 1]) % p + p) % p;
  }

 public:
  pair<int, int> expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      --left;
      ++right;
    }
    return {left + 1, right - 1};
  }

  string longestPalindrome(string s) {
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); ++i) {
      auto [left1, right1] = expandAroundCenter(s, i, i);
      auto [left2, right2] = expandAroundCenter(s, i, i + 1);
      if (right1 - left1 > end - start) {
        start = left1;
        end = right1;
      }
      if (right2 - left2 > end - start) {
        start = left2;
        end = right2;
      }
    }
    return s.substr(start, end - start + 1);
  }

  string longestPalindrome3(string s) {
    int n = s.size();
    preH = vector<long long>(n + 1, 0);
    sufH = vector<long long>(n + 2, 0);
    powB = vector<long long>(n + 1, 0);
    powB[0] = 1;
    for (int i = 1; i < n; i++) {
      preH[i] = (preH[i - 1] * b + (s[i - 1] - 'a' + 1)) % p;
      powB[i] = powB[i - 1] * b % p;
    }
    for (int i = n; i >= 1; i--) {
      sufH[i] = (sufH[i + 1] * b + (s[i - 1] - 'a' + 1)) % p;
    }
    int ansLen = 0, ansStart = 0;

    // 奇回文串
    for (int centre = 0; centre < n; centre++) {
      // 二分求从centre往两边可以扩展多少字符
      int left = 0, right = min(centre, n - 1 - centre);
      while (left < right) {
        int mid = left + ((right - left + 1) >> 1);
        if (calcHash(centre - mid, centre + mid) ==
            calcReverseHash(centre - mid, centre + mid))
          left = mid;
        else
          right = mid - 1;
      }

      if (2 * right + 1 > ansLen) {
        ansLen = 2 * right + 1;
        ansStart = centre - right;
      }
    }

    // 偶回文串
    for (int centre = 1; centre < n; centre++) {
      // 二分求从centre往两边可以扩展多少字符
      int left = -1, right = min(centre - 1, n - 1 - centre);
      while (left < right) {
        int mid = left + ((right - left + 1) >> 1);
        if (calcHash(centre - 1 - mid, centre + mid) ==
            calcReverseHash(centre - 1 - mid, centre + mid))
          left = mid;
        else
          right = mid - 1;
      }

      if (2 * right + 2 > ansLen) {
        ansLen = 2 * right + 2;
        ansStart = centre - 1 - right;
      }
    }
    return s.substr(ansStart, ansLen);
  }

  /**
   * 奇偶回文
   */
  string longestPalindrome2(string s) {
    int n = s.size(), ansLen = 0, ansStart = 0;
    // 奇回文串
    for (int centre = 0; centre < n; centre++) {
      int l = centre - 1, r = centre + 1;
      while (l >= 0 && r < n && s[l] == s[r]) {
        l--, r++;
      }

      if (r - l - 1 > ansLen) {
        ansLen = r - l - 1;
        ansStart = l + 1;
      }
    }

    // 偶回文串
    for (int centre = 1; centre < n; centre++) {
      int l = centre - 1, r = centre;
      while (l >= 0 && r < n && s[l] == s[r]) {
        l--, r++;
      }
      if (r - l - 1 > ansLen) {
        ansLen = r - l - 1;
        ansStart = l + 1;
      }
    }
    return s.substr(ansStart, ansLen);
  }
};
// @lc code=end
