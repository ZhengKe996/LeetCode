/*
 * @lc app=leetcode.cn id=28 lang=java
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
    public int strStr(String haystack, String needle) {
        int b = 131, p = (int) 1e9 + 7, n = haystack.length(), m = needle.length();

        long[] H = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            H[i] = (H[i - 1] * b + (haystack.charAt(i - 1) - 'a' + 1)) % p;
        }

        long Hneedle = 0, powBM = 1;
        for (char ch : needle.toCharArray()) {
            Hneedle = (Hneedle * b + (ch - 'a' + 1)) % p;
            powBM = powBM * b % p;
        }
        for (int l = 1; l <= n - m + 1; l++) {
            int r = l + m - 1;
            if (((H[r] - H[l - 1] * powBM) % p + p) % p == Hneedle) {
                return l - 1;
            }
        }
        return -1;
    }
}
// @lc code=end
