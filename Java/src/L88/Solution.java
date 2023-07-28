package L88;

import java.sql.Array;
import java.util.ArrayList;

public class Solution {
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] result = new int[m + n];
        int i = 0, j = 0, k = 0;
        while ((i < m || j < n)) {
            if (j >= n || i < m && nums1[i] < nums2[j]) {
                result[k] = nums1[i++];
            } else {
                result[k] = nums2[j++];

            }
            k++;
        }
        for (int in = 0; in < nums1.length; in++) {
            nums1[in] = result[in];
        }
    }

    public static void merge2(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1, j = n - 1;
        for (int k = m + n - 1; k >= 0; k--) {
            if (j < 0 || (i >= 0 && nums1[i] >= nums2[j])) nums1[k] = nums1[i--];
            else nums1[k] = nums2[j--];
        }
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3, 0, 0, 0};
        int m = 3;
        int[] nums2 = {2, 5, 6};
        int n = 3;
        merge2(nums1, m, nums2, n);

        for (int i = 0; i < nums1.length; i++) {
            System.out.println(nums1[i]);
        }

    }
}
