#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (h.find(target - nums[i]) != h.end()) {
                return {h[target - nums[i]], i};
            }
            h[nums[i]] = i;
        }
        return {};
    }

    vector<int> twoSum2(vector<int> &nums, int target) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums.size(); i++) {
            pairs.push_back({nums[i], i});
        }

        sort(pairs.begin(), pairs.end());
        int j = pairs.size() - 1;
        for (int i = 0; i < pairs.size(); i++) {
            while (i < j && pairs[i].first + pairs[j].first > target) {
                j--;
            }

            if (i < j && pairs[i].first + pairs[j].first == target) {
                return {pairs[i].second, pairs[j].second};
            }
        }
        return {};

    }

private:
    unordered_map<int, int> h;
};

int main() {
    Solution s;
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    vector<int> result = s.twoSum(nums, target);
    for (int j = 0; j < result.size(); ++j) {
        cout << result[j] << " ";
    }
    return 0;
}
