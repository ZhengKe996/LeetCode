#include <iostream>
using namespace std;
class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    // 0.Move index to 1-based
    int n = prices.size();
    prices.insert(prices.begin(), 0);

    // 1.Define f, initialize 负无穷
    vector<vector<vector<int>>> f(
        n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1e9)));

    f[0][0][0] = 0;  // 合法起点

    // 2. Loop over all states;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 2; j++) {
        for (int p = 0; p <= k; p++) {
          // 3. Copy decisions 抄决策方程
          if (p > 0)
            f[i][1][p] = max(f[i][1][p], f[i - 1][0][p - 1] - prices[i]);
          f[i][0][p] = max(f[i][0][p], f[i - 1][1][p] + prices[i]);
          f[i][j][p] = max(f[i][j][p], f[i - 1][j][p]);
        }
      }
    }

    // 4. Return target
    int ans = -1e9;
    for (int i = 0; i <= k; i++) {
      ans = max(ans, f[n][0][i]);
    }
    return ans;
  }
};
int main() {
  Solution s;
  int k = 2;
  vector<int> prices = {2, 4, 1};
  cout << s.maxProfit(k, prices);
  return 0;
}