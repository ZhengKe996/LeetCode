package L15;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    /**
     * 双指针+两数之和
     *
     * @param nums
     * @return
     */
    public static List<List<Integer>> threeSum(int[] nums) {
        // 先排序
        int n = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<List<Integer>>();

        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            List<List<Integer>> jks = twoSum(nums, i + 1, -nums[i]);
            for (List<Integer> jk : jks) {
                ArrayList<Integer> list = new ArrayList<>();
                list.add(nums[i]);
                list.add(jk.get(0));
                list.add(jk.get(1));
                ans.add(list);
            }
        }
        return ans;
    }

    private static List<List<Integer>> twoSum(int[] numbers, int start, int target) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        int j = numbers.length - 1;
        for (int i = start; i < numbers.length; i++) {
            if (i > start && numbers[i] == numbers[i - 1]) {
                continue;
            }

            while (i < j && numbers[i] + numbers[j] > target) {
                j--;
            }
            if (i < j && numbers[i] + numbers[j] == target) {
                ;
                ArrayList<Integer> list = new ArrayList<>();
                list.add(numbers[i]);
                list.add(numbers[j]);
                ans.add(list);
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = {-1, 0, 1, 2, -1, -4};
        List<List<Integer>> list = threeSum(nums);
        for (int i = 0; i < list.size(); i++) {
            for (int j = 0; j < list.get(i).size(); j++) {
                System.out.print(list.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }
}
