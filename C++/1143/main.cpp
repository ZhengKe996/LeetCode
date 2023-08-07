#include <iostream>
using namespace std;

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    text1 = " " + text1, text2 = " " + text2;
    vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (text1[i] == text2[j]) {
          f[i][j] = f[i - 1][j - 1] + 1;
        } else {
          f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
      }
    }
    return f[m][n];
  };
  int longestCommonSubsequence2(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    text1 = " " + text1;
    text2 = " " + text2;
    vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
    vector<vector<int>> preType(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (text1[i] == text2[j]) {
          f[i][j] = f[i - 1][j - 1] + 1;
          preType[i][j] = 2;
        } else {
          if (f[i - 1][j] > f[i][j - 1]) {
            f[i][j] = f[i - 1][j];
            preType[i][j] = 0;
          } else {
            f[i][j] = f[i][j - 1];
            preType[i][j] = 1;
          }
        }
      }
    }
    print(text1, text2, preType, m, n);
    return f[m][n];
  };

  void print(string text1, string text2, vector<vector<int>> &preType, int i,
             int j) {
    if (i == 0 || j == 0) return;

    if (preType[i][j] == 0)
      print(text1, text2, preType, i - 1, j);
    else if (preType[i][j] == 1)
      print(text1, text2, preType, i, j - 1);
    else
      print(text1, text2, preType, i - 1, j - 1);
  }
};
int main() {
  Solution s;
  string text1 = "abcde", text2 = "ace";
  int ans = s.longestCommonSubsequence(text1, text2);
  int ans2 = s.longestCommonSubsequence2(text1, text2);
  cout << ans << " " << ans2 << endl;
  return 0;
}