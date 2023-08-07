package L1665;

import java.util.Arrays;

public class Solution {
    public int minimumEffort(int[][] tasks) {
        Arrays.sort(tasks, (x, y) -> (y[1] - y[0]) - (x[1] - x[0]));
        int ans = 0;
        for (int i = tasks.length - 1; i >= 0; i--) {
            ans = Math.max(tasks[i][1], ans + tasks[i][0]);
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] tasks = { { 1, 2 }, { 2, 4 }, { 4, 8 } };
        int ans = solution.minimumEffort(tasks);
        System.out.println(ans);
    }
}
