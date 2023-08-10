package L1334;

public class Solution {

    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        // 邻接矩阵
        int[][] d = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = (int) 1e9;
            }
        }

        for (int i = 0; i < n; i++) {
            d[i][i] = 0;
        }

        for (int[] edge : edges) {
            int x = edge[0];
            int y = edge[1];
            int z = edge[2];
            d[x][y] = d[y][x] = z;
        }

        // Floyd
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);

                }
            }
        }

        int ans = 0;
        int minMeighbour = (int) 1e9;
        for (int i = 0; i < n; i++) {
            int neighour = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && d[i][j] <= distanceThreshold)
                    neighour++;
            }
            if (neighour < minMeighbour || neighour == minMeighbour && i > ans) {
                minMeighbour = neighour;
                ans = i;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        int n = 4;
        int[][] edges = { { 0, 1, 3 }, { 1, 2, 1 }, { 1, 3, 4 }, { 2, 3, 1 } };
        int distanceThreshold = 4;
        Solution solution = new Solution();
        System.out.println(solution.findTheCity(n, edges, distanceThreshold));
    }

}
