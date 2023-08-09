#include <iostream>
using namespace std;

class Solution {
 public:
  int mergeStones(vector<int>& stones, int k) {
    int n = stones.size();
    vector<vector<vector<int>>> f(
        n, vector<vector<int>>(n, vector<int>(k + 1, 1e9)));
    for (int l = 0; l < n; l++) f[l][l][1] = 0;
    for (int len = 2; len <= n; len++) {
      for (int l = 0; l < n - len + 1; l++) {
        int r = l + len - 1;
        for (int i = 2; i <= k; i++) {
          for (int p = l; p < r; p++) {
            f[l][r][i] = min(f[l][r][i], f[l][p][1] + f[p + 1][r][i - 1]);
          }
        }
        int sum = 0;
        for (int p = l; p <= r; p++) sum += stones[p];
        f[l][r][1] = min(f[l][r][1], f[l][r][k] + sum);
      }
    }
    return f[0][n - 1][1] == 1e9 ? -1 : f[0][n - 1][1];
  }
};
int main() {
  Solution s;
  vector<int> stones = {3, 2, 4, 1};
  int k = 2;
  cout << s.mergeStones(stones, k);
}