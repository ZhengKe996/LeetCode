#include <iostream>

using namespace std;

class Solution {
public:
    int splitArray(vector<int> &nums, int k) {
        int l = 0, r = 0;
        for (int num: nums) {
            l = max(l, num);
            r += num;
        }
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (validate(nums, k, mid)) { r = mid; }
            else l = mid + 1;

        }
        return r;
    }

private:
    bool validate(vector<int> &nums, int m, int size) {
        int box = 0, count = 1;
        for (int num: nums) {
            if (box + num <= size) box += num;
            else {
                count++;
                box = num;
            }
        }
        return count <= m;
    }
};

int main() {
    Solution s;
    vector<int> nums = {7, 2, 5, 10, 8};
    int m = 2;
    int ans = s.splitArray(nums, m);
    cout << ans;
    return 0;
}
