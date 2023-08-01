#include <iostream>

using namespace std;

class Solution {
private:
    vector<int> vis;

    void backtrack(vector<int> &nums, vector<vector<int>> &ans, int idx, vector<int> &perm) {
        if (idx == nums.size()) {
            ans.push_back(perm);
            return;
        }
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, idx + 1, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, perm);
        return ans;
    }
};

int main() {
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {1, 2, 3};
    Solution s;
    vector<vector<int>> asn1 = s.permuteUnique(nums1);
    vector<vector<int>> asn2 = s.permuteUnique(nums2);
    for (int i = 0; i < asn1.size(); ++i) {
        for (int j = 0; j < asn1[i].size(); ++j) {
            cout << asn1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------" << endl;
    for (int i = 0; i < asn2.size(); ++i) {
        for (int j = 0; j < asn2[i].size(); ++j) {
            cout << asn2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
