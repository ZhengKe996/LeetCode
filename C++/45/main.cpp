#include <iostream>
using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    int now = 0, ans = 0;
    while (now < nums.size() - 1) {
      int right = now + nums[now];
      if (right >= nums.size() - 1) return ans + 1;
      int nextRight = right;
      int next = now;
      for (int i = now + 1; i <= right; i++) {
        if (i + nums[i] > nextRight) {
          nextRight = i + nums[i];
          next = i;
        }
      }
      now = next;
      ans++;
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums = {2, 3, 1, 1, 4};
  int ans = s.jump(nums);
  cout << ans << endl;
  return 0;
}