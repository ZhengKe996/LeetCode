#include <iostream>
#include <queue>

using namespace std;

class Solution {
 private:
  vector<int> dist;
  vector<vector<int>> ver;
  vector<vector<int>> edge;
  vector<bool> expend;
  priority_queue<pair<int, int>> queue;

 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    dist = vector<int>(n + 1, 1e9);
    dist[k] = 0;
    for (int round = 1; round <= n - 1; round++) {
      bool flag = false;
      for (vector<int>& edge : times) {
        int x = edge[0];
        int y = edge[1];
        int z = edge[2];
        if (dist[x] + z < dist[y]) {
          dist[y] = dist[x] + z;
          flag = true;
        }
      }
      if (!flag) break;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dist[i]);
    return ans == 1e9 ? -1 : ans;
  }

  /**
   * Diikstra 第一版
   */
  int networkDelayTime2(vector<vector<int>>& times, int n, int k) {
    ver = vector<vector<int>>(n + 1, vector<int>());
    edge = vector<vector<int>>(n + 1, vector<int>());

    for (vector<int>& t : times) {
      int x = t[0];
      int y = t[1];
      int z = t[2];
      ver[x].push_back(y);
      edge[x].push_back(z);
    }

    dist = vector<int>(n + 1, 1e9);
    dist[k] = 0;
    expend = vector<bool>(n + 1, false);

    for (int round = 1; round <= n - 1; round++) {
      int temp = 1e9, x;
      for (int i = 1; i <= n; i++) {
        if (!expend[i] && dist[i] < temp) {
          temp = dist[i];
          x = i;
        }
      }
      expend[x] = true;
      for (int i = 0; i < ver[x].size(); i++) {
        int y = ver[x][i];
        int z = edge[x][i];
        if (dist[y] > dist[x] + z) {
          dist[y] = dist[x] + z;
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dist[i]);
    return ans == 1e9 ? -1 : ans;
  }

  /**
   * Diikstra 堆优化
   */
  int networkDelayTime3(vector<vector<int>>& times, int n, int k) {
    ver = vector<vector<int>>(n + 1, vector<int>());
    edge = vector<vector<int>>(n + 1, vector<int>());

    for (vector<int>& t : times) {
      int x = t[0];
      int y = t[1];
      int z = t[2];
      ver[x].push_back(y);
      edge[x].push_back(z);
    }

    dist = vector<int>(n + 1, 1e9);
    dist[k] = 0;
    expend = vector<bool>(n + 1, false);
    queue.push({0, k});

    while (!queue.empty()) {
      int x = queue.top().second;
      queue.pop();
      if (expend[x]) continue;
      expend[x] = true;

      for (int i = 0; i < ver[x].size(); i++) {
        int y = ver[x][i];
        int z = edge[x][i];
        if (dist[y] > dist[x] + z) {
          dist[y] = dist[x] + z;
          queue.push({-dist[y], y});
        }
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dist[i]);
    return ans == 1e9 ? -1 : ans;
  }
};

int main() {
  vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
  int n = 4, k = 2;

  Solution s;

  cout << s.networkDelayTime(times, n, k) << endl;
  cout << s.networkDelayTime2(times, n, k) << endl;
  cout << s.networkDelayTime3(times, n, k) << endl;
}