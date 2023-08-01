#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        n = nums.size();
        used = vector<bool>(n, false);
        recur(nums, 0);
        return ans;
    }

private:
    vector<bool> used;
    vector<int> a;
    int n;
    vector<vector<int>> ans;

    void recur(vector<int> &nums, int pos) {
        if (pos == n) {
            ans.push_back(a);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                a.push_back(nums[i]);
                used[i] = true;
                recur(nums, pos + 1);
                used[i] = false;
                a.pop_back();
            }
        }
    }

};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s;
    vector<vector<int>> ans = s.permute(nums);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
