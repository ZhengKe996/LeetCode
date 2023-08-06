package L912;

import java.util.Random;

public class Solution {
    public int[] sortArray(int[] nums) {
        if (nums == null || nums.length < 2) return nums;
        quickSort(nums, 0, nums.length - 1);
        return nums;
    }

    private void quickSort(int[] arr, int l, int r) {
        if (l >= r) return;
        int mid = partition(arr, l, r);
        quickSort(arr, l, mid);
        quickSort(arr, mid + 1, r);
    }

    private int partition(int[] arr, int l, int r) {
        if (l > r) return -1;
        if (l == r) return l;
        int mid = l + (int) Math.random() % (r - l + 1);
        int midVal = arr[mid];
        while (l <= r) {
            while (arr[l] < midVal)l++;
            while (arr[r] > midVal)r--;
            if (l == r)break;
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
        int[] nums = {5, 1, 1, 2, 0, 0};
        int[] ans = solution.sortArray(nums);
        for (int i = 0; i < ans.length; ++i) {
            System.out.print(ans[i] + " ");
        }
    }
}
