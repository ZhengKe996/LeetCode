package L455;

import java.util.Arrays;

public class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int j = 0, ans = 0;
        for (int child : g) {
            while (j < s.length && s[j] < child)
                j++;
            if (j < s.length) {
                ans++;
                j++;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] g = { 1, 2, 3 }, s = { 1, 1 };
        int ans = solution.findContentChildren(g, s);
        System.out.println(ans);
    }
}
