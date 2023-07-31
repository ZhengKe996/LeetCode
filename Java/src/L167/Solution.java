package L167;

class Solution {
    public static int[] twoSum(int[] numbers, int target) {
        int j = numbers.length - 1;
        for (int i = 0; i < numbers.length; i++) {
            while (i < j && numbers[i] + numbers[j] > target) j--;
            if (i < j && numbers[i] + numbers[j] == target) return new int[]{i + 1, j + 1};
        }
        return new int[]{-1, 1};
    }

    public static void main(String[] args) {
        int[] numbers = {2, 7, 11, 15};
        int target = 9;
        int[] res = twoSum(numbers, target);
        int[] numbers2 = {2, 3, 4};
        for (int i = 0; i < res.length; i++) {
            System.out.print(res[i] + " ");
        }
        System.out.println();
        int target2 = 6;
        int[] res2 = twoSum(numbers2, target2);
        for (int i = 0; i < res2.length; i++) {
            System.out.print(res2[i] + " ");
        }
    }
}