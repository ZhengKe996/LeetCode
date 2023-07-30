#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * 横向考虑
     * @param heights
     * @return
     */
    int trap(vector<int> &heights) {
        int ans = 0;
        for (int height: heights) {
            int accumulatedWidth = 0; // 累加宽度
            while (!s.empty() && s.top().height <= height) {
                int bottom = s.top().height;
                accumulatedWidth += s.top().width;
                s.pop();

                if (s.empty()) {// 栈为空 则最左侧水要流走
                    continue;
                }
                // 以bottom为底的横块水最高可以到up（左右两侧的高度的min）
                int up = min(height, s.top().height);
                ans += accumulatedWidth * (up - bottom);
            }
            s.push({accumulatedWidth + 1, height});
        }
        return ans;
    }

    /**
     * 前缀后缀最大值
     * @param heights
     * @return
     */
    int trap2(vector<int> &heights) {
        int n = heights.size();
        preMax = vector<int>(n);
        sufMax = vector<int>(n);
        preMax[0] = heights[0];

        for (int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i - 1], heights[i]);
        }
        sufMax[n - 1] = heights[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            sufMax[i] = max(sufMax[i + 1], heights[i]);
        }

        int ans = 0;
        // 枚举每个数条
        for (int i = 1; i < n - 1; i++) {
            int up = min(preMax[i - 1], sufMax[i + 1]);
            int bottom = heights[i];
            if (up > bottom) { // 能存水
                ans += (up - bottom);
            }
        }


        return ans;
    }

private:
    struct Rect {
        int width;
        int height;
    };
    stack<Rect> s;

    vector<int> preMax;
    vector<int> sufMax;
};


int main() {
    Solution s;
    vector<int> height{4, 2, 0, 3, 2, 5};
    cout << s.trap(height) << " ";
    cout << s.trap2(height);
    return 0;
}