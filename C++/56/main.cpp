#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> ans;
        int farthest = -1, start = -1;
        for (const vector<int> &interval: intervals) {
            int left = interval[0], right = interval[1];
            if (left <= farthest) farthest = max(farthest, right);
            else {
                if (farthest != -1)ans.push_back({start, farthest});
                start = left;
                farthest = right;
            }
        }
        ans.push_back({start, farthest});
        return ans;
    }

    /**
     * 差分思想
     * @param intervals
     * @return
     */
    vector<vector<int>> merge2(vector<vector<int>> &intervals) {
        vector<pair<int, int>> events;
        for (const vector<int> &interval: intervals) {
            events.push_back({interval[0], 1});
            events.push_back({interval[1] + 1, -1});
        }
        sort(events.begin(), events.end());
        int covering = 0, start = 0;
        vector<vector<int>> ans;
        for (const pair<int, int> &event: events) {
            if (covering == 0)start = event.first;
            covering += event.second;
            if (covering == 0) ans.push_back({start, event.first - 1});
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals = {{1,  3},
                                     {2,  6},
                                     {8,  10},
                                     {15, 18}};
    vector<vector<int>> ans = s.merge(intervals);
    vector<vector<int>> ans2 = s.merge2(intervals);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ans2[i][j] << endl;
        }
        cout << "---------------" << endl;
    }
    return 0;
}
