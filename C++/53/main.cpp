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
};


int main() {

    Solution s;
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int res = s.maxSubArray(nums);
    cout << res;

    return 0;
}
