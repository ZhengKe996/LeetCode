#include <iostream>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int k = 2;
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
  vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
  cout << s.maxProfit(prices);
  return 0;
}