#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        int l = 0, r = nums.size() - 1, mid = 0;

        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    Solution s;
    int ans = s.search(nums, 9);
    cout << ans;

    return 0;
}
