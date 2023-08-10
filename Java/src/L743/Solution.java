package L743;

import java.util.Arrays;

public class Solution {
    private int[] dist;

    public int networkDelayTime(int[][] times, int n, int k) {

        dist = new int[n + 1];
        for (int i = 0; i < dist.length; i++) {
            dist[i] = (int) 1e9;
        }
        dist[k] = 0;

        for (int round = 1; round <= n - 1; round++) {
            boolean flag = false;
            for (int[] edge : times) {
                int x = edge[0];
                int y = edge[1];
                int z = edge[2];
                if (dist[x] + z < dist[y]) {
                    dist[y] = dist[x] + z;
                    flag = true;
                }
            }
            if (!flag)
                break;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = Math.max(ans, dist[i]);
        return ans == 1e9 ? -1 : ans;
    }

    public int networkDelayTime2(int[][] times, int n, int k) {
        final int INF = Integer.MAX_VALUE / 2;
        int[][] g = new int[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(g[i], INF);
        }
        for (int[] t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x][y] = t[2];
        }

        int[] dist = new int[n];
        Arrays.fill(dist, INF);
        dist[k - 1] = 0;
        boolean[] used = new boolean[n];
        for (int i = 0; i < n; ++i) {
            int x = -1;
            for (int y = 0; y < n; ++y) {
                if (!used[y] && (x == -1 || dist[y] < dist[x])) {
                    x = y;
                }
            }
            used[x] = true;
            for (int y = 0; y < n; ++y) {
                dist[y] = Math.min(dist[y], dist[x] + g[x][y]);
            }
        }

        int ans = Arrays.stream(dist).max().getAsInt();
        return ans == INF ? -1 : ans;
    }

    public static void main(String[] args) {
        int[][] times = { { 2, 1, 1 }, { 2, 3, 1 }, { 3, 4, 1 } };
        int n = 4, k = 2;

        Solution solution = new Solution();
        System.out.println(solution.networkDelayTime(times, n, k));
        System.out.println(solution.networkDelayTime2(times, n, k));
    }
}
