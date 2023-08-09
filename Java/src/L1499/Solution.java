package L1499;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;

public class Solution {
    private Deque<Integer> q = new LinkedList<>();

    public int findMaxValueOfEquation(int[][] points, int k) {
        int ans = (int) -1e9;

        for (int i = 0; i < points.length; i++) {
            while (!q.isEmpty() && points[q.peek()][0] < points[i][0] - k) {
                q.poll();
            }

            if (!q.isEmpty()) {
                ans = Math.max(ans, points[i][1] + points[i][0] + points[q.peek()][1] -
                        points[q.peek()][0]);
            }
            while (!q.isEmpty() && points[q.getLast()][1] - points[q.getLast()][0] <= points[i][1] - points[i][0]) {
                q.pollLast();
            }
            q.add(i);
        }
        return ans;
    }

    public int findMaxValueOfEquation2(int[][] points, int k) {
        int res = Integer.MIN_VALUE;
        Deque<int[]> queue = new ArrayDeque<int[]>();
        for (int[] point : points) {
            int x = point[0], y = point[1];
            while (!queue.isEmpty() && x - queue.peekFirst()[1] > k) {
                queue.pollFirst();
            }
            if (!queue.isEmpty()) {
                res = Math.max(res, x + y + queue.peekFirst()[0]);
            }
            while (!queue.isEmpty() && y - x >= queue.peekLast()[0]) {
                queue.pollLast();
            }
            queue.offer(new int[] { y - x, x });
        }
        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] points = { { 1, 3 }, { 2, 0 }, { 5, 10 }, { 6, -10 } };
        int k = 1;
        System.out.println(solution.findMaxValueOfEquation(points, k));
        System.out.println(solution.findMaxValueOfEquation2(points, k));
    }
}
