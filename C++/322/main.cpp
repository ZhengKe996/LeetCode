#include <iostream>
using namespace std;

class Solution {
 public:
  void coinChange(vector<int>& coins, int amount, int c_index, int count,
                  int& ans) {
    if (amount == 0) {
      ans = min(ans, count);
      return;
    }
    if (c_index == coins.size()) return;
    if (vi[amount][c_index] <= count) return;

    for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--) {
      int nextAmount = amount - k * coins[c_index];
      coinChange(coins, nextAmount, c_index + 1, count + k, ans);
    }
    vi[amount][c_index] = min(vi[amount][c_index], count);
  }

  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    sort(coins.rbegin(), coins.rend());
    int ans = INT_MAX;
    vi = vector<vector<int>>(amount + 1, vector<int>(coins.size(), INT_MAX));
    coinChange(coins, amount, 0, 0, ans);
    return ans == INT_MAX ? -1 : ans;
  }

  /**
   *动态规划
   */
  int coinChange2(vector<int>& coins, int amount) {
    int INF = (int)1e9;
    vector<int> opt(amount + 1, 0);
    opt[0] = 0;
    for (int i = 1; i <= amount; i++) {
      opt[i] = INF;
      for (int j = 0; j < coins.size(); j++) {
        if (i - coins[j] >= 0) opt[i] = min(opt[i], opt[i - coins[j]] + 1);
      }
    };
    if (opt[amount] >= INF) opt[amount] = -1;
    return opt[amount];
  }

 private:
  vector<vector<int>> vi;
};

int main() {
  Solution s;
  vector<int> coins = {1, 2, 5};
  int amount = 11;
  int ans = s.coinChange(coins, amount);
  int ans2 = s.coinChange2(coins, amount);
  cout << ans << "  " << ans2 << endl;
  return 0;
}