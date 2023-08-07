#include <iostream>

using namespace std;

class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int j = 0, ans = 0;
    for (int child : g) {
      while (j < s.size() && s[j] < child) j++;
      if (j < s.size()) {
        ans++;
        j++;
      }
    }
    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> g = {1, 2, 3}, s = {1, 1};
  int ans = solution.findContentChildren(g, s);
  cout << ans << endl;
  return 0;
}