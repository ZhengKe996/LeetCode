package L329;

import java.util.*;

class Solution2 {
    private int m, n;
    private int[] dx = {-1, 0, 0, 1};
    private int[] dy = {0, -1, 1, 0};
    private int[][] dist;
    private int[][] matrix;

    /**
     * 记忆化搜索
     *
     * @param matrix
     * @return
     */
    public int longestIncreasingPath(int[][] matrix) {
        this.m = matrix.length;
        this.n = matrix[0].length;
        this.dist = new int[m][n];
        this.matrix = matrix;
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = Math.max(ans, dfs(i, j));
            }
        }
        return ans;
    }

    private int dfs(int x, int y) {
        if (dist[x][y] != 0) return dist[x][y];
        dist[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny) && matrix[nx][ny] > matrix[x][y]) {
                dist[x][y] = Math.max(dist[x][y], dfs(nx, ny) + 1);
            }
        }
        return dist[x][y];
    }

    private boolean valid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
}

public class Solution {
    private int m, n;
    private int[] deg, dist;
    private Set<Integer>[] to;

    private int[] dx = {-1, 0, 0, 1};
    private int[] dy = {0, -1, 1, 0};

    private void addEdge(int u, int v) {
        deg[v]++;
        if (to[u] == null) to[u] = new HashSet<>();
        to[u].add(v);

    }

    private int num(int i, int j) {
        return i * n + j;
    }

    private boolean valid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    public int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        this.m = matrix.length;
        this.n = matrix[0].length;
        this.to = new HashSet[m * n];
        this.deg = new int[m * n];
        this.dist = new int[m * n];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (valid(ni, nj) && matrix[ni][nj] > matrix[i][j]) {
                        addEdge(num(i, j), num(ni, nj));
                    }
                }
            }
        }

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < m * n; ++i) {
            if (deg[i] == 0) {
                queue.add(i);
                dist[i] = 1;
            }
        }

        while (!queue.isEmpty()) {
            int x = queue.poll();
            if (to[x] != null) {
                for (int y : to[x]) {
                    deg[y]--;
                    dist[y] = Math.max(dist[y], dist[x] + 1);
                    if (deg[y] == 0) queue.add(y);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m * n; ++i) {
            ans = Math.max(ans, dist[i]);
        }
        return ans;
    }


    public int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    public int rows, columns;

    /**
     * 官方解法：记忆化深度优先搜索
     *
     * @param matrix
     * @return
     */
    public int longestIncreasingPath2(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        rows = matrix.length;
        columns = matrix[0].length;
        int[][] memo = new int[rows][columns];
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                ans = Math.max(ans, dfs(matrix, i, j, memo));
            }
        }
        return ans;
    }

    public int dfs(int[][] matrix, int row, int column, int[][] memo) {
        if (memo[row][column] != 0) {
            return memo[row][column];
        }
        ++memo[row][column];
        for (int[] dir : dirs) {
            int newRow = row + dir[0], newColumn = column + dir[1];
            if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[row][column]) {
                memo[row][column] = Math.max(memo[row][column], dfs(matrix, newRow, newColumn, memo) + 1);
            }
        }
        return memo[row][column];
    }


    /**
     * 拓扑排序
     *
     * @param matrix
     * @return
     */
    public int longestIncreasingPath3(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        rows = matrix.length;
        columns = matrix[0].length;
        int[][] outdegrees = new int[rows][columns];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                for (int[] dir : dirs) {
                    int newRow = i + dir[0], newColumn = j + dir[1];
                    if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[i][j]) {
                        ++outdegrees[i][j];
                    }
                }
            }
        }
        Queue<int[]> queue = new LinkedList<int[]>();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (outdegrees[i][j] == 0) {
                    queue.offer(new int[]{i, j});
                }
            }
        }
        int ans = 0;
        while (!queue.isEmpty()) {
            ++ans;
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                int[] cell = queue.poll();
                int row = cell[0], column = cell[1];
                for (int[] dir : dirs) {
                    int newRow = row + dir[0], newColumn = column + dir[1];
                    if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] < matrix[row][column]) {
                        --outdegrees[newRow][newColumn];
                        if (outdegrees[newRow][newColumn] == 0) {
                            queue.offer(new int[]{newRow, newColumn});
                        }
                    }
                }
            }
        }
        return ans;
    }

    private int[][] direction = new int[][]{{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    public int longestIncreasingPath4(int[][] matrix) {
        if (matrix == null || matrix.length == 0)
            return 0;
        m = matrix.length;
        n = matrix[0].length;
        int maxLen = 0;
        int[][] dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxLen = Math.max(maxLen, dfs(matrix, dp, i, j));
            }
        }
        return maxLen;
    }

    private int dfs(int[][] matrix, int[][] dp, int r, int c) {
        if (dp[r][c] != 0)
            return dp[r][c];

        for (int[] d : direction) {
            if (valid(r + d[0], c + d[1]) && matrix[r][c] < matrix[r + d[0]][c + d[1]]) {
                dp[r][c] = Math.max(dp[r][c], dfs(matrix, dp, r + d[0], c + d[1]));
            }
        }
        return ++dp[r][c];
    }


    public static void main(String[] args) {
        Solution solution = new Solution();
        Solution2 solution2 = new Solution2();
        int[][] matrix = {{9, 9, 4},
                {6, 6, 8},
                {2, 1, 1}};
        int ans = solution.longestIncreasingPath(matrix);
        int ans2 = solution.longestIncreasingPath2(matrix);
        int ans3 = solution.longestIncreasingPath3(matrix);
        int ans4 = solution.longestIncreasingPath4(matrix);
        int ans5 = solution2.longestIncreasingPath(matrix);
        System.out.println(ans + "-----" + ans2 + "-----" + ans3 + "-----" + ans4 + "-----" + ans5);

        int[][] matrix2 = {{3, 4, 5},
                {3, 2, 6},
                {2, 2, 1}};
        ans = solution.longestIncreasingPath(matrix2);
        ans2 = solution.longestIncreasingPath2(matrix2);
        ans3 = solution.longestIncreasingPath3(matrix2);
        ans4 = solution.longestIncreasingPath4(matrix2);
        ans5 = solution2.longestIncreasingPath(matrix2);
        System.out.println(ans + "-----" + ans2 + "-----" + ans3 + "-----" + ans4 + "-----" + ans5);

        int[][] matrix3 = {{1}};
        ans = solution.longestIncreasingPath(matrix3);
        ans2 = solution.longestIncreasingPath2(matrix3);
        ans3 = solution.longestIncreasingPath3(matrix3);
        ans4 = solution.longestIncreasingPath4(matrix3);
        ans5 = solution2.longestIncreasingPath(matrix3);
        System.out.println(ans + "-----" + ans2 + "-----" + ans3 + "-----" + ans4 + "-----" + ans5);
    }
}
