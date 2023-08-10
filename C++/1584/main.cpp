#include <iostream>

using namespace std;

class Solution {
 private:
  vector<int> fa;
  int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
  }

 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<vector<int>> edges;
    fa = vector<int>(n, 0);
    for (int i = 0; i < n; i++) fa[i] = i;
    // 建边
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        edges.push_back({i, j,
                         abs(points[i][0] - points[j][0]) +
                             abs(points[i][1] - points[j][1])});
      }
    }

    sort(
        edges.begin(), edges.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[2] < b[2]; });

    // 扫描每条边
    int ans = 0;
    for (vector<int>& edge : edges) {
      int x = edge[0];
      int y = edge[1];
      int z = edge[2];
      x = find(x);
      y = find(y);
      if (x != y) {
        ans += z;
        fa[x] = y;
      }
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
  Solution s;

  cout << s.minCostConnectPoints(points);
}