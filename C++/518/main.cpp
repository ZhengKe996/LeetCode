#include <iostream>
using namespace std;

class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    int n = coins.size();
    coins.insert(coins.begin(), 0);

    vector<int> f(amount + 1, 0);
    f[0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = coins[i]; j <= amount; j++) {
        f[j] += f[j - coins[i]];
      }
    }
    return f[amount];
  }
};

int main() {
  Solution s;
  int amount = 5;
  vector<int> coins = {1, 2, 5};
  cout << s.change(amount, coins);
}