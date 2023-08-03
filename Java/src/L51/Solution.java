package L51;

import java.util.*;

class Solution {
    final int N = 20;
    List<List<String>> res = new ArrayList<>();//返回结果
    boolean[] col, diagonal, rdiagonal;

    public List<List<String>> solveNQueens(int n) {
        char[][] g = new char[n][n];

        col = new boolean[N];//标记行号
        diagonal = new boolean[N];//标记对角线
        rdiagonal = new boolean[N];//标记反对角线

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = '.';
            }
        }
        dfs(0, n, g);
        return res;

    }

    void dfs(int u, int n, char[][] g) {
        if (u == n) {
            List<String> single = new ArrayList<>();//存储单个棋盘

            for (int i = 0; i < n; i++) {
                single.add(new String(g[i]));//字符数组转换字符串
            }
            res.add(single);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!col[i] && !diagonal[u + i] && !rdiagonal[n - u + i]) {
                g[u][i] = 'Q';//标记走过
                col[i] = diagonal[u + i] = rdiagonal[n - u + i] = true;
                dfs(u + 1, n, g);
                g[u][i] = '.';//回溯恢复现场
                col[i] = diagonal[u + i] = rdiagonal[n - u + i] = false;
            }
        }

    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        List<List<String>> ans = solution.solveNQueens(4);
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans.get(i).size(); j++) {
                System.out.println(ans.get(i).get(j) + " ");
            }
            System.out.println("====================");
        }
    }
}