#include <iostream>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> s(n + 1);
    vector<int> preMin(n + 1);
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1] + nums[i - 1];
    }
    preMin[0] = s[0];
    for (int i = 1; i <= n; i++) {
      preMin[i] = min(preMin[i - 1], s[i]);
    }
    int ans = -1000000;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, s[i] - preMin[i - 1]);
    }
    return ans;
  }

  /**
   * 动态规划
   */
  int maxSubArray2(vector<int> &nums) {
    int n = nums.size();
    vector<int> f(n, 0);
    f[0] = nums[0];
    for (int i = 1; i < n; i++) {
      f[i] = max(f[i - 1] + nums[i], nums[i]);
    }
    int ans = f[0];
    for (int i = 1; i < n; i++) {
      ans = max(ans, f[i]);
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int res = s.maxSubArray(nums);
  int res2 = s.maxSubArray2(nums);
  cout << res << " " << res2;

  return 0;
}
