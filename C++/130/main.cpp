#include <iostream>

using namespace std;

class Solution {
 private:
  const int dx[4] = {-1, 0, 0, 1};
  const int dy[4] = {0, -1, 1, 0};

  int m, n;
  int num(int i, int j) { return i * n + j; }
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
  void solve(vector<vector<char>>& board) {
    m = board.size();
    n = board[0].size();
    fa = vector<int>(m * n + 1, 0);
    for (int i = 0; i <= m * n; i++) fa[i] = i;

    int outside = m * n;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'X') continue;
        for (int k = 0; k < 4; k++) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          if (ni < 0 || nj < 0 || ni >= m || nj >= n) {
            UnionSet(num(i, j), outside);
          } else {
            if (board[ni][nj] == 'O') UnionSet(num(i, j), num(ni, nj));
          }
        }
      }
    }

    outside = find(outside);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'O' && find(num(i, j)) != outside) {
          board[i][j] = 'X';
        }
      }
    }
  }
};

int main() {
  vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                {'X', 'O', 'O', 'X'},
                                {'X', 'X', 'O', 'X'},
                                {'X', 'O', 'X', 'X'}};
  Solution s;
  s.solve(board);
}