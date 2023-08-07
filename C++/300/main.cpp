#include <iostream>

using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> f(n, 0);
    for (int i = 0; i < n; i++) f[i] = 1;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, f[i]);
    }
    return ans;
  }

  int lengthOfLIS2(vector<int>& nums) {
    int n = nums.size();
    vector<int> f(n, 0);
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++) {
      f[i] = 1;
      pre[i] = -1;
    }

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          f[i] = max(f[i], f[j] + 1);
          pre[i] = j;
        }
      }
    }
    int ans = 0;
    int end = -1;
    for (int i = 0; i < n; i++) {
      if (f[i] > ans) {
        ans = f[i];
        end = i;
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  int ans = s.lengthOfLIS(nums);
  int ans2 = s.lengthOfLIS2(nums);
  cout << ans << " " << ans2;
  return 0;
}