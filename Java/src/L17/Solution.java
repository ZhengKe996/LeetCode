package L17;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {
    private String digits;
    private StringBuffer str = new StringBuffer();
    private List<String> ans;
    private Map<Character, String> alphabet;

    public List<String> letterCombinations(String digits) {
        this.digits = digits;
        ans = new ArrayList<>();
        alphabet = new HashMap<>() {{
            put('2', "abc");
            put('3', "def");
            put('4', "ghi");
            put('5', "jkl");
            put('6', "mno");
            put('7', "pqrs");
            put('8', "tuv");
            put('9', "wxyz");
        }};
        if (digits.isEmpty()) return new ArrayList<>();
        dfs(0);
        return ans;
    }

    private void dfs(Integer index) {
        if (index == digits.length()) {
            ans.add(str.toString());
            return;
        }
        char digit = digits.charAt(index);
        String letters = alphabet.get(digit);
        for (char ch : letters.toCharArray()) {
            str.append(ch);
            dfs(index + 1);
            str.deleteCharAt(str.length() - 1);
        }

    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        List<String> list = solution.letterCombinations("23");
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }
    }
}
