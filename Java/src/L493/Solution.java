package L493;

public class Solution {
    private int ans = 0;

    private void mergeSort(int[] arr, int l, int r) {
        if (l >= r) return;
        int mid = l + ((r - l) >> 1);
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        calculate(arr, l, mid, r);
        merge(arr, l, mid, r);
    }

    void calculate(int[] arr, int left, int mid, int right) {
        int j = mid;
        for (int i = left; i <= mid; ++i) {
            while (j < right && arr[i] > 2l * arr[j + 1]) j++;
            ans += j - mid;
        }
    }

    void merge(int[] arr, int left, int mid, int right) {
        int[] temp = new int[right - left + 1];
        int i = left, j = mid + 1;
        for (int k = 0; k < temp.length; ++k) {
            if (j > right || (i <= mid && arr[i] <= arr[j])) temp[k] = arr[i++];
            else temp[k] = arr[j++];
        }
        for (int k = 0; k < temp.length; ++k) {
            arr[left + k] = temp[k];
        }
    }

    public int reversePairs(int[] nums) {
        ans = 0;
        mergeSort(nums, 0, nums.length - 1);
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {1, 3, 2, 3, 1};
        int i = solution.reversePairs(nums);
        System.out.println(i);
    }
}
