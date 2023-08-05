#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> ans;
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        ans.push_back(right);

        left = -1;
        right = nums.size() - 1;
        while (left < right) {
            int mid = left + ((right - left + 1) >> 1);
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }
        ans.push_back(right);
        if (ans[0] > ans[1])return {-1, -1};
        else return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> ans = s.searchRange(nums, target);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
