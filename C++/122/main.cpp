#include <iostream>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    for (int i = 1; i < prices.size(); i++) {
      ans += max(prices[i] - prices[i - 1], 0);
    }
    return ans;
  }
  int maxProfit2(vector<int>& prices) {
    // 0.Move index to 1-based
    int n = prices.size();
    prices.insert(prices.begin(), 0);

    // 1.Define f, initialize 负无穷
    vector<vector<int>> f(n + 1, vector<int>(2, -1e9));
    f[0][0] = 0;  // 合法起点

    // 2. Loop over all states;
    for (int i = 1; i <= n; i++) {
      // 3. Copy decisions 抄决策方程
      f[i][1] = max(f[i][1], f[i - 1][0] - prices[i]);
      f[i][0] = max(f[i][0], f[i - 1][1] + prices[i]);
      for (int j = 0; j < 2; j++) {
        f[i][j] = max(f[i][j], f[i - 1][j]);
      }
    }

    // 4. Return target
    return f[n][0];
  }
};

int main() {
  Solution s;
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  int ans = s.maxProfit(prices);
  int ans2 = s.maxProfit2(prices);
  cout << ans << " " << ans2 << endl;
  return 0;
}