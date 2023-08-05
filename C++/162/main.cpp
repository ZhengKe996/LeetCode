#include <iostream>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left+right>>1;
            if (nums[mid] <= nums[mid+1]) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int ans = s.findPeakElement(nums);
    cout << ans;
    return 0;
}
