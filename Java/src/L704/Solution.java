package L704;

public class Solution {

    public int search(int[] nums, int target) {

        int l = 0, r = nums.length - 1, mid = 0;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {-1, 0, 3, 5, 9, 12};
        int ans = solution.search(nums, 9);
        System.out.println(ans);
    }
}
