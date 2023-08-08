#include <iostream>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 0);
    if (n = 1) return nums[1];
    vector<vector<int>> f(n + 1, vector<int>(2, -1e9));
    f[1][0] = 0;
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < 2; j++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        f[i][1] = f[i - 1][0] + nums[i];
      };
    }
    int ans = max(f[n][0], f[n][1]);

    f[1][0] = 0;
    f[1][1] = nums[1];
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < 2; j++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        f[i][1] = f[i - 1][0] + nums[i];
      }
    }

    return max(ans, f[n][0]);
  }
};

int main() {
  Solution s;
  vector<int> nums = {2, 3, 2};
  cout << s.rob(nums);
}