#include <iostream>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // 0.Move index to 1-based
    int n = prices.size();

    prices.insert(prices.begin(), 0);

    // 1.Define f, initialize 负无穷
    vector<vector<vector<int>>> f(n + 1,
                                  vector<vector<int>>(2, vector<int>(2, -1e9)));

    f[0][0][0] = 0;  // 合法起点

    // 2. Loop over all states;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 2; j++) {
        for (int l = 0; l < 2; l++) {
          // 3. Copy decisions 抄决策方程
          if (l == 0) f[i][1][0] = max(f[i][1][0], f[i - 1][0][0] - prices[i]);

          // 卖出股票会冷冻
          f[i][0][1] = max(f[i][0][1], f[i - 1][1][0] + prices[i]);
          f[i][j][0] = max(f[i][j][0], f[i - 1][j][l]);
        }
      }
    }

    // 4. Return target
    return max(f[n][0][1], f[n][0][0]);
  };

  int maxProfit2(vector<int>& prices) {
    // 0.Move index to 1-based
    int n = prices.size();

    prices.insert(prices.begin(), 0);

    // 1.Define f, initialize 负无穷
    vector<vector<vector<int>>> f(n + 1,
                                  vector<vector<int>>(2, vector<int>(2, -1e9)));

    f[0][0][0] = 0;  // 合法起点

    // 2. Loop over all states;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        for (int l = 0; l < 2; l++) {
          if (f[i][j][l] == -1e9) continue;
          // 3. Copy decisions 抄决策方程
          if (j == 0 && l == 0)
            f[i + 1][1][0] = max(f[i + 1][1][0], f[i][j][l] - prices[i + 1]);
          if (j == 1 && l == 0)
            f[i + 1][0][1] = max(f[i + 1][0][1], f[i][j][l] + prices[i + 1]);
          f[i + 1][j][0] = max(f[i + 1][j][0], f[i][j][l]);
        }
      }
    }

    // 4. Return target
    return max(f[n][0][1], f[n][0][0]);
  }
};

int main() {
  Solution s;
  vector<int> prices = {1, 2, 3, 0, 2};
  cout << s.maxProfit(prices) << " " << s.maxProfit2(prices);
  return 0;
}