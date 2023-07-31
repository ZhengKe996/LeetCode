package L30;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {
    public static List<Integer> findSubstring(String s, String[] words) {
        int n = s.length(), m = words.length, w = words[0].length();

        Map<String, Integer> map = new HashMap<>();

        for (String word : words) map.put(word, map.getOrDefault(word, 0) + 1);
        List<Integer> ans = new ArrayList<>();
        out:
        for (int i = 0; i + m * w <= n; i++) {
            Map<String, Integer> cur = new HashMap<>();
            String sub = s.substring(i, i + m * w);
            for (int j = 0; j < sub.length(); j += w) {
                String item = sub.substring(j, j + w);
                if (!map.containsKey(item)) continue out;
                cur.put(item, cur.getOrDefault(item, 0) + 1);
            }
            if (cur.equals(map)) ans.add(i);
        }
        return ans;
    }

    public static List<Integer> findSubstring2(String s, String[] words) {
        List<Integer> res = new ArrayList<Integer>();
        int m = words.length, n = words[0].length(), ls = s.length();
        for (int i = 0; i < n; i++) {
            if (i + m * n > ls) {
                break;
            }
            Map<String, Integer> differ = new HashMap<String, Integer>();
            for (int j = 0; j < m; j++) {
                String word = s.substring(i + j * n, i + (j + 1) * n);
                differ.put(word, differ.getOrDefault(word, 0) + 1);
            }
            for (String word : words) {
                differ.put(word, differ.getOrDefault(word, 0) - 1);
                if (differ.get(word) == 0) {
                    differ.remove(word);
                }
            }
            for (int start = i; start < ls - m * n + 1; start += n) {
                if (start != i) {
                    String word = s.substring(start + (m - 1) * n, start + m * n);
                    differ.put(word, differ.getOrDefault(word, 0) + 1);
                    if (differ.get(word) == 0) {
                        differ.remove(word);
                    }
                    word = s.substring(start - n, start);
                    differ.put(word, differ.getOrDefault(word, 0) - 1);
                    if (differ.get(word) == 0) {
                        differ.remove(word);
                    }
                }
                if (differ.isEmpty()) {
                    res.add(start);
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        String str = "barfoothefoobarman";
        String[] words = {"foo", "bar"};
        List<Integer> list = findSubstring(str, words);
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }
    }
}
