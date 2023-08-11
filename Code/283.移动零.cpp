/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int n = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {  // 遍历数组若数组元素不为0则赋值
        nums[n] = nums[i];
        n++;
      }
    }
    while (n < nums.size()) {
      nums[n] = 0;  // 在最后补0
      n++;
    }
  }
};
// @lc code=end
