package L34;

public class Solution {

    public int[] searchRange(int[] nums, int target) {
        int[] ans = new int[2];
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        ans[0] = right;
        left = -1; right = nums.length-1;
        while (left < right) {
            int mid = left + ((right - left + 1) >> 1);
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }
        ans[1] = right;

        if (ans[0] > ans[1]) return new int[]{-1, -1};
        else return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {5, 7, 7, 8, 8, 10};
        int target = 8;
        int[] ints = solution.searchRange(nums, target);
        for (int i = 0; i < ints.length; i++) {
            System.out.print(ints[i] + " ");
        }
    }
}

