#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        to = vector<vector<int>>(numCourses, vector<int>());
        inDeg = vector<int>(numCourses, 0);

        for (vector<int> &pre: prerequisites) {
            int ai = pre[0];
            int bi = pre[1];
            to[bi].push_back(ai);
            inDeg[ai]++;
        }

        queue<int> q;
        // 拓扑排序第一步：从零入度点出发
        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> lessons;

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            lessons.push_back(x);

            // 第二步：扩展一个点，周围的点入度-1
            for (int y: to[x]) {
                inDeg[y]--;
                // 第三步：入度减为0，表示可以入队了
                if (inDeg[y] == 0) {
                    q.push(y);
                }
            }
        }
        return lessons.size() == numCourses;
    }

private:
    vector<vector<int>> to;
    vector<int> inDeg;
};

int main() {
    Solution s;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    auto res = s.canFinish(numCourses, prerequisites);
    cout << res;
    return 0;
}
