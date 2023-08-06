package L215;

import java.util.Arrays;

public class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length - k];
    }

    public int findKthLargest2(int[] nums, int k) {
        return quickSort(nums, 0, nums.length - 1, nums.length - k);
    }

    private int quickSort(int[] arr, int l, int r, int index) {
        if (l >= r) return arr[l];
        int mid = partition(arr, l, r);
        if (index <= mid) return quickSort(arr, l, mid, index);
        else return quickSort(arr, mid + 1, r, index);
    }

    private int partition(int[] arr, int l, int r) {
        if (l > r) return -1;
        if (l == r) return l;
        int mid = l + (int) Math.random() % (r - l + 1);
        int midVal = arr[mid];
        while (l <= r) {
            while (arr[l] < midVal) l++;
            while (arr[r] > midVal) r--;
            if (l == r) break;
            if (l < r) {
                int temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
                l++;
                r--;
            }
        }
        return r;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {3, 2, 1, 5, 6, 4};
        int k = 2;
        int ans = solution.findKthLargest(nums, k);
        int ans2 = solution.findKthLargest2(nums, k);
        System.out.println(ans + " " + ans2);
    }
}
