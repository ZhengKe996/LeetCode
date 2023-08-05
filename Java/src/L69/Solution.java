package L69;

public class Solution {
    public long mySqrt(int x) {
        long l = 0, r = x;
        while (l < r) {
            long mid = l + ((r - l + 1) >> 1);
            if (mid <= x / mid) l = mid;
            else r = mid - 1;
        }
        return r;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        long i = solution.mySqrt(4);
        System.out.println(i);
    }
}
