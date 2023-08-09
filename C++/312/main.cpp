#include <iostream>

using namespace std;

class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> f(n + 2, vector<int>(n + 2, 0));
    for (int len = 1; len <= n; len++) {
      for (int l = 1; l <= n - len + 1; l++) {
        int r = l + len - 1;
        for (int p = l; p <= r; p++) {
          f[l][r] = max(f[l][r], f[l][p - 1] + f[p + 1][r] +
                                     nums[p] * nums[l - 1] * nums[r + 1]);
        }
      }
    }
    return f[1][n];
  }

  int maxCoins2(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        f[i][j] = -1;
      }
    }

    return calc(1, n, nums, f);
  }
  int calc(int l, int r, vector<int>& nums, vector<vector<int>>& f) {
    if (l > r) return 0;
    if (f[l][r] != -1) return f[l][r];
    for (int i = l; i <= r; i++) {
      f[l][r] = max(f[l][r], calc(l, i - 1, nums, f) + calc(i + 1, r, nums, f) +
                                 nums[i] * nums[l - 1] * nums[r + 1]);
    }
    return f[l][r];
  }
};

int main() {
  Solution s;
  vector<int> nums = {3, 1, 5, 8};
  cout << s.maxCoins(nums) << endl;
  cout << s.maxCoins2(nums);
}