#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1);
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1] % 2;
        }

        vector<int> count(n + 1);
        int ans = 0;
        count[s[0]]++;

        for (int i = 1; i <= n; i++) {
            if (s[i] - k >= 0) {
                ans += count[s[i] - k];
            }
            count[s[i]]++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 1, 2, 1, 1};
    int k = 3;
    int res = s.numberOfSubarrays(nums, k);
    cout << res;
    return 0;
}
