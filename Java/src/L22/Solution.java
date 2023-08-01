package L22;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

public class Solution {
    private HashMap<Integer, List<String>> store = new HashMap<>();

    public List<String> generateParenthesis(int n) {
        if (n == 0) return new ArrayList<>(Collections.singleton(""));
        if (store.containsKey(n)) return store.get(n);

        List<String> ans = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            List<String> A = generateParenthesis(i - 1);
            List<String> B = generateParenthesis(n - i);
            for (String a : A) {
                for (String b : B) {
                    ans.add("(" + a + ")" + b);
                }
            }
        }
        store.put(n, ans);
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        List<String> list = solution.generateParenthesis(3);
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + " ");
        }
        System.out.println();
        List<String> list1 = solution.generateParenthesis(1);
        for (int i = 0; i < list1.size(); i++) {
            System.out.print(list1.get(i) + " ");
        }
    }
}
