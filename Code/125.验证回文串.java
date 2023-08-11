/*
 * @lc app=leetcode.cn id=125 lang=java
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
    public boolean isPalindrome(String s) {
        StringBuffer t = new StringBuffer();
        for (char ch : s.toCharArray()) {
            if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z')
                t.append(ch);
            else if (ch >= 'A' && ch <= 'Z')
                t.append(Character.toLowerCase(ch));
        }

        // 2. 双指针进行比较
        int l = 0, r = t.length() - 1;
        while (l < r) {
            if (t.charAt(l) != t.charAt(r))
                return false;
            l++;
            r--;
        }
        return true;
    }
}
// @lc code=end
