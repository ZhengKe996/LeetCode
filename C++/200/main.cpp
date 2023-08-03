#include <iostream>
#include <queue>

using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<bool>> visited;

    void dfs(vector<vector<char>> &grid, int sx, int sy) {
        queue<pair<int, int>> q;
        const int dx[4] = {-1, 0, 0, 1};
        const int dy[4] = {0, -1, 1, 0};
        q.push({sx, sy});
        visited[sx][sy] = true;
        while (!q.empty()) {
            // 第一步：取队头
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            // 第二步：扩展队头
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }
                if (grid[nx][ny] != '1')continue;
                if (visited[nx][ny])continue;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    void dfs2(vector<vector<char>> &grid, int sx, int sy) {
        int m = grid.size();
        int n = grid[0].size();
        if (sx < 0 || sx >= m || sy < 0 || sy >= n || grid[sx][sy] == '0' || visited[sx][sy]) {
            return;
        }
        visited[sx][sy] = true;
        dfs2(grid, sx - 1, sy);
        dfs2(grid, sx + 1, sy);
        dfs2(grid, sx, sy - 1);
        dfs2(grid, sx, sy + 1);
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }

    int numIslands2(vector<vector<char>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    dfs2(grid, i, j);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<char>> grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}};

    int ans = s.numIslands(grid);
    cout << ans << endl;

    vector<vector<char>> grid2 = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}};


    ans = s.numIslands(grid2);
    cout << ans << endl;
    cout << "==========" << endl;

    int ans1 = s.numIslands2(grid);
    cout << ans1 << endl;

    ans1 = s.numIslands2(grid2);
    cout << ans1 << endl;

    return 0;
}
