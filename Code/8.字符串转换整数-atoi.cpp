/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
 public:
  int myAtoi(string s) {
    int index = 0;
    // 1.读入字符串并丢弃无用的前导空格
    while (index < s.length() && s[index] == ' ') index++;
    /**
     * 2.检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。确定最终结果是负数还是正数。
     * 如果两者都不存在，则假定结果为正。
     */
    int sign = 1;
    if (index < s.length() && (s[index] == '+' || s[index] == '-')) {
      sign = s[index] == '+' ? 1 : -1;
      index++;
    }
    /**
     * 3.读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略
     */
    int val = 0;
    while (index < s.length() && s[index] >= '0' && s[index] <= '9') {
      /**
       * 5.如果整数数超过 32 位有符号整数范围 [−231,  231 −
      1],需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231
      的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
      */
      if (val > (2147483647 - (s[index] - '0')) / 10) {
        if (sign == 1)
          return 2147483647;
        else
          return -2147483648;
      }

      val = val * 10 + (s[index] - '0');
      index++;
    }
    return sign * val;
  }
};
// @lc code=end
