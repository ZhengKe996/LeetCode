#include <iostream>

using namespace std;

class Solution {
private:
    int n;
    vector<int> p;
    vector<bool> used;
    unordered_map<int, bool> usedPlus;
    unordered_map<int, bool> usedMinus;
    vector<vector<int>> ans;

    void dfs(int row) {
        if (row == n) {
            ans.push_back(p);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (!used[col] && !usedPlus[row + col] && !usedMinus[row - col]) {
                p.push_back(col);
                used[col] = true;
                usedPlus[row + col] = true;
                usedMinus[row - col] = true;
                dfs(row + 1);
                // 还原现场
                used[col] = false;
                usedPlus[row + col] = false;
                usedMinus[row - col] = false;
                p.pop_back();
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        used = vector<bool>(n);
        vector<vector<string>> result;
        dfs(0);
        for (vector<int> &p: ans) {
            vector<string> pattern(n, string(n, '.'));
            for (int row = 0; row < n; ++row) {
                pattern[row][p[row]] = 'Q';
            }
            result.push_back(pattern);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<string >> ans = s.solveNQueens(4);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " " << endl;
        }
        cout << "==================" << endl;
    }
    return 0;
}
