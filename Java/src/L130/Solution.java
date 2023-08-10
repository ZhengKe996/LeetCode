package L130;

public class Solution {

    private final int dx[] = { -1, 0, 0, 1 };
    private final int dy[] = { 0, -1, 1, 0 };
    private int m, n;
    private int[] fa;

    int num(int i, int j) {
        return i * n + j;
    }

    int find(int x) {
        if (x == fa[x])
            return x;
        return fa[x] = find(fa[x]);
    }

    void UnionSet(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y)
            fa[x] = y;
    }

    public void solve(char[][] board) {
        m = board.length;
        n = board[0].length;
        fa = new int[m * n + 1];
        for (int i = 0; i <= m * n; i++)
            fa[i] = i;

        int outside = m * n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X')
                    continue;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n) {
                        UnionSet(num(i, j), outside);
                    } else {
                        if (board[ni][nj] == 'O')
                            UnionSet(num(i, j), num(ni, nj));
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
}
