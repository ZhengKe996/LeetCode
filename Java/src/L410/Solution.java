package L410;

public class Solution {
    private boolean validate(int[] nums, int m, int size) {
        int box = 0, count = 1;
        for (int num : nums) {
            if (box + num <= size) box += num;
            else {
                count++;
                box = num;
            }
        }
        return count <= m;
    }

    public int splitArray(int[] nums, int k) {
        int l = 0, r = 0;
        for (int num : nums) {
            l = Math.max(l, num);
            r += num;
        }
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (validate(nums, k, mid)) {
                r = mid;
            } else l = mid + 1;

        }
        return r;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {7, 2, 5, 10, 8};
        int m = 2;
        int i = solution.splitArray(nums, m);
        System.out.println(i);
    }
}
