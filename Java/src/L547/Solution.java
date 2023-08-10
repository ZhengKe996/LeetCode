package L547;

public class Solution {
    private int[] fa;

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

    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        fa = new int[n];
        for (int i = 0; i < n; i++)
            fa[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1)
                    UnionSet(i, j);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                ans++;
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] isConnected = { { 1, 1, 0 }, { 1, 1, 0 }, { 0, 0, 1 } };
        System.out.println(solution.findCircleNum(isConnected));
    }
}
