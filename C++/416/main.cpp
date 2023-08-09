#include <iostream>

using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 0);
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += nums[i];
    if (sum % 2 == 1) return false;
    vector<int> f(sum / 2 + 1, false);
    f[0] = true;
    for (int i = 1; i <= n; i++) {
      for (int j = sum / 2; j >= nums[i]; j--) {
        f[j] |= f[j - nums[i]];
      }
    }
    return f[sum / 2];
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 5, 11, 5};
  cout << s.canPartition(nums);
}