#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        for (vector<int> &edge: edges) {
            int x = edge[0];
            int y = edge[1];
            n = max(n, max(x, y));
        }

        to = vector<vector<int>>(n + 1, vector<int>());
        visited = vector<bool>(n + 1, false);

        for (vector<int> &edge: edges) {
            int x = edge[0];
            int y = edge[1];
            // 出边数组加边的方法
            to[x].push_back(y);
            to[y].push_back(x);

            // 循环前清空数组
            for (int i = 1; i <= n; i++) {
                visited[i] = false;
            }
            hasCycle = false; // true 时有环
            dfs(x, 0);

            if (hasCycle) {
                return edge;
            }
        }

        return {};
    }

private:
    // 图深度优先遍历判断环的模版
    void dfs(int x, int father) {
        visited[x] = true;
        // 出边数组访问x能到的周围点方法
        for (int y: to[x]) {
            if (y == father) {
                continue;
            }
            if (!visited[y]) {
                dfs(y, x);
            } else {
                hasCycle = true;
            }
        }
    }

    bool hasCycle;
    int n;
    vector<vector<int>> to;
    vector<bool> visited;
};

int main() {
    Solution s;
    vector<vector<int>> edges = {{1, 2},
                                 {1, 3},
                                 {2, 3}};

    vector<int> ans = s.findRedundantConnection(edges);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
