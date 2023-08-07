package L860;

import java.util.HashMap;
import java.util.Map;

public class Solution {
    private Map<Integer, Integer> coins = new HashMap<>();

    public boolean lemonadeChange(int[] bills) {
        coins.put(5, 0);
        coins.put(10, 0);
        coins.put(20, 0);

        for (int bill : bills) {
            int value = coins.get(bill);
            value++;
            coins.put(bill, value);
            if (!exchange(bill - 5))
                return false;
        }
        return true;
    }

    private boolean exchange(int amount) {
        int[] w = { 20, 10, 5 };
        for (int x : w) {
            while (amount >= x && coins.get(x) > 0) {
                amount -= x;
                int value = coins.get(x);
                value--;
                coins.put(x, value);
            }
        }
        return amount == 0;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] bills = { 5, 5, 5, 10, 20 };
        boolean ans = solution.lemonadeChange(bills);
        System.out.println(ans);
    }
}
