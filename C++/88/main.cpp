#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < m || j < n) {
            // j出界 或者 i没出界且i处的元素值小于j处的元素值
            if (j >= n || i < m && nums1[i] <= nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            } else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = res[i];
        }
    }

    void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1, j = n - 1;
        for (int k = m + n - 1; k >= 0; k--) {
            if (j < 0 || (i >= 0 && nums1[i] >= nums2[j])) {
                nums1[k] = nums1[i--];
            } else {
                nums1[k] = nums2[j--];
            }
        }
    }
};

int main() {
    Solution s;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    s.merge2(nums1, m, nums2, n);

    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }

    return 0;
}
