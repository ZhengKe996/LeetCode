#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int n = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) { // 遍历数组若数组元素不为0则赋值
                nums[n] = nums[i];
                n++;
            }
        }
        while (n < nums.size()) {
            nums[n] = 0;// 在最后补0
            n++;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    return 0;
}
