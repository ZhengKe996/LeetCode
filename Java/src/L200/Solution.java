package L200;


class Solution {
    private int[] dx = {-1, 0, 0, 1};
    private int[] dy = {0, -1, 1, 0};
    private boolean[][] visited;

    private void dfs(char[][] grid, int sx, int sy) {
        int m = grid.length;
        int n = grid[0].length;
        if (sx < 0 || sx >= m || sy < 0 || sy >= n || grid[sx][sy] == '0' || visited[sx][sy]) {
            return;
        }
        visited[sx][sy] = true;
        dfs(grid, sx - 1, sy);
        dfs(grid, sx + 1, sy);
        dfs(grid, sx, sy - 1);
        dfs(grid, sx, sy + 1);
    }

    public int numIslands(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        visited = new boolean[m][n];
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        char[][] grid = {
                {'1', '1', '1', '1', '0'},
                {'1', '1', '0', '1', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '0', '0', '0'}};
        System.out.println(solution.numIslands(grid));
        char[][] grid2 = {
                {'1', '1', '0', '0', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '1', '0', '0'},
                {'0', '0', '0', '1', '1'}};
        System.out.println(solution.numIslands(grid2));

    }
}