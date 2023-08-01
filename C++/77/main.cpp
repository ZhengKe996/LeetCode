#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        recur(1);
        return ans;
    }

private:
    int n, k;
    vector<int> chosen;
    vector<vector<int>> ans;

    void recur(int i) {
        if (i == n + 1) {
            if (chosen.size() == k) ans.push_back(chosen);
            return;
        }
        recur(i + 1);
        chosen.push_back(i);
        recur(i + 1);
        chosen.pop_back();
    }
};

int main() {
    Solution s;
    vector<vector<int>> ans = s.combine(4, 2);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
