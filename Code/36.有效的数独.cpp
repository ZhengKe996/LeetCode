/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include <iostream>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<char> row[9];
    unordered_set<char> col[9];
    unordered_set<char> box[9];
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char digit = board[i][j];
        if (digit == '.') continue;
        if (row[i].find(digit) != row[i].end()) return false;
        row[i].insert(digit);
        if (col[j].find(digit) != col[j].end()) return false;
        col[j].insert(digit);

        int k = (i / 3) * 3 + j / 3;  // 将二维转为一维数组
        if (box[k].find(digit) != box[k].end()) return false;
        box[k].insert(digit);
      }
    }
    return true;
  }
};
// @lc code=end
