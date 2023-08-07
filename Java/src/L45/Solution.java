package L45;

public class Solution {
    public int jump(int[] nums) {
        int now = 0, ans = 0;
        while (now < nums.length - 1) {
            int right = now + nums[now];
            if (right >= nums.length - 1)
                return ans + 1;
            int nextRight = right, next = now;
            for (int i = now + 1; i <= right; i++) {
                if (i + nums[i] > nextRight) {
                    nextRight = i + nums[i];
                    next = i;
                }
            }
            now = next;
            ans++;
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = { 2, 3, 1, 1, 4 };
        int ans = solution.jump(nums);
        System.out.println(ans);

    }

}
