#include <iostream>

using namespace std;

class Solution {
private:
    int ans;

    void mergeSort(vector<int> &arr, int l, int r) {
        if (l >= r) return;
        int mid = l + ((r - l) >> 1);
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        calculate(arr, l, mid, r);
        merge(arr, l, mid, r);
    }

    void calculate(vector<int> &arr, int left, int mid, int right) {
        int j = mid;
        for (int i = left; i <= mid; ++i) {
            while (j < right && arr[i] > 2l * arr[j + 1])j++;
            ans += j - mid;
        }
    }

    void merge(vector<int> &arr, int left, int mid, int right) {
        vector<int> temp(right - left + 1, 0);
        int i = left, j = mid + 1;
        for (int k = 0; k < temp.size(); ++k) {
            if (j > right || (i <= mid && arr[i] <= arr[j])) temp[k] = arr[i++];
            else temp[k] = arr[j++];
        }
        for (int k = 0; k < temp.size(); ++k) {
            arr[left + k] = temp[k];
        }
    }

public:
    int reversePairs(vector<int> &nums) {
        ans = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 2, 3, 1};
    int ans = s.reversePairs(nums);
    cout << ans << endl;
    return 0;
}
