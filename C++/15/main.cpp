#include <iostream>

using namespace std;

/**
 * 分模块思想 基于二数和 完成三数
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // 1. 先排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            vector<vector<int>> jks = twoSum(nums, i + 1, -nums[i]);
            for (vector<int> jk: jks) {
                ans.push_back({nums[i], jk[0], jk[1]});
            }
        }
        return ans;

    }


private:
    vector<vector<int>> twoSum(vector<int> &numbers, int start, int target) {
        vector<vector<int>> ans;
        int j = numbers.size() - 1;
        for (int i = start; i < numbers.size(); i++) {
            if (i > start && numbers[i] == numbers[i - 1]) {
                continue;
            }

            while (i < j && numbers[i] + numbers[j] > target) {
                j--;
            }
            if (i < j && numbers[i] + numbers[j] == target) {
                ans.push_back({numbers[i], numbers[j]});
            }
        }
        return ans;
    }

};

int main() {
    Solution s;
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = s.threeSum(nums);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
