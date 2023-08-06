#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int> &arr, int l, int r) {
        if (l >= r)return;
        int mid = partition(arr, l, r);
        quickSort(arr, l, mid);
        quickSort(arr, mid + 1, r);
    }

    int partition(vector<int> &a, int l, int r) {
        int mid = l + rand() % (r - l + 1);
        int midVal = a[mid];
        while (l <= r) {
            while (a[l] < midVal)l++;
            while (a[r] > midVal)r--;
            if (l == r)break;
            if (l < r) {
                int temp = a[l];
                a[l] = a[r];
                a[r] = temp;
                l++;
                r--;
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 1, 1, 2, 0, 0};
    vector<int> ans = s.sortArray(nums);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
