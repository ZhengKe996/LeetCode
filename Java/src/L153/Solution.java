package L153;

public class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = l+((r - l) >> 1);
            if (nums[mid] <= nums[r]) r = mid;
            else l = mid + 1;
        }
        return nums[r];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {3, 4, 5, 1, 2};
        int min = solution.findMin(nums);
        System.out.println(min);
    }
}
