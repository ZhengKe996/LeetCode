#include <iostream>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }

    int findKthLargest2(vector<int> &nums, int k) {
        return quickSort(nums, 0, nums.size() - 1, nums.size() - k);
    }

private:
    int quickSort(vector<int> &arr, int l, int r, int index) {
        if (l >= r)return arr[l];
        int mid = partition(arr, l, r);
        if (index <= mid) return quickSort(arr, l, mid, index);
        else return quickSort(arr, mid + 1, r, index);
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
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int ans = s.findKthLargest(nums, k);
    int ans2 = s.findKthLargest2(nums, k);
    cout << ans<<" " << ans2 << endl;
    return 0;
}
