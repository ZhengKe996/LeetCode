#include <iostream>
using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<int> fmax(n, 0);
    vector<int> fmin(n, 0);
    fmax[0] = nums[0];
    fmin[0] = nums[0];
    for (int i = 1; i < n; i++) {
      fmax[i] = max(max(fmax[i - 1] * nums[i], fmin[i - 1] * nums[i]), nums[i]);
      fmin[i] = min(min(fmax[i - 1] * nums[i], fmin[i - 1] * nums[i]), nums[i]);
    }
    int ans = fmax[0];
    for (int i = 1; i < n; i++) {
      ans = max(ans, fmax[i]);
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums = {2, 3, -2, 4};
  cout << s.maxProduct(nums);
  return 0;
}