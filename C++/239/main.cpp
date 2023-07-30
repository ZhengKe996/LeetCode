#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> ans;
        // 下标（时间）递增，值递减的队列
        for (int i = 0; i < nums.size(); i++) {
            // 删除出界的选项
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }

            // 插入新选项i，维护单调性（值递减）
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);

            // 取队头更新答案；
            if (i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }

private:
    deque<int> q;// 存储下标
};


int main() {
    Solution s;
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = s.maxSlidingWindow(nums, k);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    return 0;
}
