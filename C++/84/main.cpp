#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int ans = 0;
        heights.push_back(0); // 保证最后栈被弹空
        for (int height: heights) {
            int accumulatedWith = 0; // 累加宽度

            // 操作栈顶 满足单调性（单调性被破坏）； 栈顶（高度）>=当前高度，单调性破坏，确定了栈顶高度的扩展范围，需要删除栈顶；
            while (!s.empty() && s.top().height >= height) {
                accumulatedWith += s.top().width; // 1. 累加高度
                ans = max(ans, s.top().height * accumulatedWith);// 2. 更新答案 确定栈顶高度的扩展范围
                s.pop();
            }

            s.push({accumulatedWith + 1, height});
        }
        return ans;
    }

private:
    struct Rect {
        int width;
        int height;
    };

    stack<Rect> s;
};

int main() {
    Solution s;
    vector<int> heights{2, 1, 5, 6, 2, 3};
    cout << s.largestRectangleArea(heights);
    return 0;
}