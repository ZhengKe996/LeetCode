package L918;

import java.util.Deque;
import java.util.LinkedList;

public class Solution {
    private Deque<Integer> q = new LinkedList<>();

    public int maxSubarraySumCircular(int[] nums) {
        int n = nums.length;

        int[] newArr = new int[n + 1];
        for (int i = 0; i < nums.length; i++) {
            newArr[i + 1] = nums[i];
        }

        int[] ss = new int[2 * n + 1];
        ss[0] = 0;
        for (int i = 1; i <= n; i++)
            ss[i] = ss[i - 1] + newArr[i];

        for (int i = n + 1; i <= 2 * n; i++)
            ss[i] = ss[i - 1] + newArr[i - n];

        int ans = (int) -1e9;
        for (int i = 1; i <= 2 * n; i++) {
            while (!q.isEmpty() && q.peek() < i - n)
                q.poll();
            if (!q.isEmpty())
                ans = Math.max(ans, ss[i] - ss[q.peek()]);
            while (!q.isEmpty() && ss[q.getLast()] >= ss[i])
                q.pollLast();
            q.add(i);
        }
        return ans;
    }

    public int maxSubarraySumCircular2(int[] nums) {

        int n = nums.length;

        int[] newArr = new int[n + 1];
        for (int i = 0; i < nums.length; i++) {
            newArr[i + 1] = nums[i];
        }

        int[] s = new int[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; i++)
            s[i] = s[i - 1] + newArr[i];
        int temp = (int) 1e9, ans = (int) -1e9;
        for (int i = 1; i <= n; i++) {
            temp = Math.min(temp, s[i - 1]);
            ans = Math.max(ans, s[i] - temp);
        }

        temp = (int) -1e9;
        int ansMin = (int) 1e9;
        for (int i = 2; i <= n; i++) {
            temp = Math.max(temp, s[i - 1]);
            ansMin = Math.min(ansMin, s[i] - temp);
        }

        for (int i = 1; i < n; i++)
            ansMin = Math.min(ansMin, s[i]);
        return Math.max(ans, s[n] - ansMin);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = { 1, -2, 3, -2 };
        System.out.println(solution.maxSubarraySumCircular(nums));
        System.out.println(solution.maxSubarraySumCircular2(nums));
    }
}
