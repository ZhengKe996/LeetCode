#include <iostream>
#include <queue>

using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<int>> to;
    vector<int> deg;
    vector<int> dist;


    void addEdge(int u, int v) {
        deg[v]++;
        to[u].push_back(v);
    }

    int num(int i, int j) {
        return i * n + j;
    }

    bool valid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        this->m = matrix.size();
        this->n = matrix[0].size();
        this->to = vector<vector<int>>(m * n, vector<int>(0));
        this->deg = vector<int>(m * n, 0);
        this->dist = vector<int>(m * n, 0);
        const int dx[4] = {-1, 0, 0, 1};
        const int dy[4] = {0, -1, 1, 0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (valid(ni, nj) && matrix[ni][nj] > matrix[i][j]) {
                        addEdge(num(i, j), num(ni, nj));
                    }
                }
            }
        }

        queue<int> q;
        for (int i = 0; i < m * n; ++i) {
            if (deg[i] == 0) {
                q.push(i);
                dist[i] = 1;
            }
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y: to[x]) {
                deg[y]--;
                dist[y] = max(dist[y], dist[x] + 1);
                if (deg[y] == 0)q.push(y);
            }
        }
        int ans = 0;
        for (int i = 0; i < m * n; ++i) {
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{9, 9, 4},
                                  {6, 6, 8},
                                  {2, 1, 1}};
    int ans = s.longestIncreasingPath(matrix);
    cout << ans << endl;
    matrix = {{3, 4, 5},
              {3, 2, 6},
              {2, 2, 1}};
    ans = s.longestIncreasingPath(matrix);
    cout << ans << endl;
    matrix = {{1}};
    ans = s.longestIncreasingPath(matrix);
    cout << ans << endl;
    return 0;
}
