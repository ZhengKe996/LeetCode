#include <iostream>

using namespace std;
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 0);
    vector<vector<int>> f(n + 1, vector<int>(2, -1e9));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 2; j++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        f[i][1] = f[i - 1][0] + nums[i];
      }
    }

    return max(f[n][0], f[n][1]);
  }
};
int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 1};

  cout << s.rob(nums);
  return 0;
}