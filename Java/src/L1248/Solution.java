package L1248;

import java.util.ArrayList;

public class Solution {
    public static int numberOfSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] s = new int[n+1];
        s[0]=0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1] % 2;
        }

        int[] count = new int[n + 1];
        int ans = 0;
        count[s[0]]++;

        for (int i = 1; i <= n; i++) {
            if (s[i] - k >= 0) {
                ans += count[s[i] - k];
            }
            count[s[i]]++;
        }

        return ans;
    }

    public static void main(String[] args) {

        int[] nums = {1, 1, 2, 1, 1};
        int k = 3;
        int res = numberOfSubarrays(nums, k);
        System.out.println(res);
    }
}
