package L162;

public class Solution {
    public int findPeakElement(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = left+right>>1;
            if (nums[mid] <= nums[mid+1]) left = mid + 1;
            else right = mid;
        }
        return right;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {1, 2, 3, 1};
        int peakElement = solution.findPeakElement(nums);
        System.out.println(peakElement);
    }
}
