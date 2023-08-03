package L684;

import java.util.*;

public class Solution {
    private int n;
    private Set<Integer>[] to;


    public int[] findRedundantConnection(int[][] edges) {
        if (edges == null || edges.length == 0 || edges[0].length == 0) {
            return new int[0];
        }
        this.n = edges.length;
        to = new HashSet[n + 1];

        for (int[] edge : edges) {
            int x = edge[0];
            int y = edge[1];
            // 出边数组加边的方法
            if (to[x] == null) {
                to[x] = new HashSet<>();
            }
            to[x].add(y);

            if (to[y] == null) {
                to[y] = new HashSet<>();
            }
            to[y].add(x);
        }

        for (int i = n - 1; i >= 0; i--) {
            to[edges[i][0]].remove(edges[i][1]);
            to[edges[i][1]].remove(edges[i][0]);
            boolean[] used = new boolean[n + 1];
            if (dfs(to, edges[i][1], edges[i][0], used)) {
                if (edges[i][1] < edges[i][0]) {
                    return new int[]{edges[i][1], edges[i][0]};
                } else {
                    return new int[]{edges[i][0], edges[i][1]};
                }
            }
        }


        return new int[0];
    }

    private boolean dfs(Set<Integer>[] map, int x, int y, boolean[] used) {
        if (x == y) return true;
        used[x] = true;

        for (int i : map[x]) {
            if (!used[i]) {
                if (dfs(map, i, y, used)) {
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] edges = {{1, 2},
                {1, 3},
                {2, 3}};

        int[] ans = solution.findRedundantConnection(edges);

        for (int i = 0; i < ans.length; i++) {
            System.out.print(ans[i] + " ");
        }
    }
}
