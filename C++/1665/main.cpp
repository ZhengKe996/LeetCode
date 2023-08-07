#include <iostream>

using namespace std;

class Solution {
 public:
  int minimumEffort(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(),
         [](const vector<int>& a, const vector<int>& b) {
           return a[0] - a[1] < b[0] - b[1];
         });
    int ans = 0;
    for (int i = tasks.size() - 1; i >= 0; i--) {
      ans = max(tasks[i][1], ans + tasks[i][0]);
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<vector<int>> tasks = {{1, 2}, {2, 4}, {4, 8}};
  int ans = s.minimumEffort(tasks);
  cout << ans;
  return 0;
}