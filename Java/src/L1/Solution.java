package L1;

import java.util.HashMap;

public class Solution {
    /**
     * 哈希表
     *
     * @param nums
     * @param target
     * @return
     */
    public static int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            if (hashMap.containsKey(target - nums[i])) {
                return new int[]{hashMap.get(target - nums[i]), i};
            }
            hashMap.put(nums[i], i);
        }
        return null;
    }

    /**
     * 双指针
     *
     * @param nums
     * @param target
     * @return
     */
    public static int[] twoSum2(int[] nums, int target) {
        int[] result = {0, 1};
        if (nums.length <= 2) return result;
        for (int i = 0; i < nums.length - 1; i++) {
            result[0] = i;
            int x = target - nums[i];
            for (int j = i + 1, k = nums.length - 1; j <= k; j++, k--) {
                if (nums[j] == x) {
                    result[1] = j;
                    return result;
                }
                if (nums[k] == x) {
                    result[1] = k;
                    return result;
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        int[] result = twoSum(nums, target);
        int[] result2 = twoSum2(nums, target);
        for (int i = 0; i < result.length; i++) {
            System.out.println(result[i] + "  " + result2[i]);
        }
    }
}
