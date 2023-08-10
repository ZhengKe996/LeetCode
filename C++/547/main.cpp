#include <iostream>

using namespace std;

class Solution {
 private:
  vector<int> fa;
  int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
  }

  void UnionSet(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) fa[x] = y;
  }

 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();

    // MakeSet
    fa = vector<int>(n, 0);
    for (int i = 0; i < n; i++) fa[i] = i;
    // 对于每条边，把两个集合合并
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isConnected[i][j]) UnionSet(i, j);
      }
    }
    // 有几个根就是有几个省份
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (find(i) == i) ans++;
    return ans;
  }
};

int main() {
  Solution s;

  vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  cout << s.findCircleNum(isConnected);
}