#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        int tot = 0;
        for (string &word: words) {
            tot += word.length();
            wordsMap[word]++;
        }

        vector<int> ans;
        for (int i = 0; i + tot <= s.length(); i++) {
            if (valid(s.substr(i, tot), words)) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    vector<int> findSubstring2(string s, vector<string> &words) {
        vector<int> res;
        int m = words.size(), n = words[0].size(), ls = s.size();
        for (int i = 0; i < n && i + m * n <= ls; ++i) {
            unordered_map<string, int> differ;
            for (int j = 0; j < m; ++j) {
                ++differ[s.substr(i + j * n, n)];
            }
            for (string &word: words) {
                if (--differ[word] == 0) {
                    differ.erase(word);
                }
            }
            for (int start = i; start < ls - m * n + 1; start += n) {
                if (start != i) {
                    string word = s.substr(start + (m - 1) * n, n);
                    if (++differ[word] == 0) {
                        differ.erase(word);
                    }
                    word = s.substr(start - n, n);
                    if (--differ[word] == 0) {
                        differ.erase(word);
                    }
                }
                if (differ.empty()) {
                    res.emplace_back(start);
                }
            }
        }
        return res;
    }

private:
    /**
     * 比较两个map是否一样
     * @param str
     * @param words
     * @return
     */
    bool valid(string str, vector<string> &words) {
        int k = words[0].length();
        unordered_map<string, int> splitWordsMap;
        for (int i = 0; i < str.length(); i += k) {
            splitWordsMap[str.substr(i, k)]++;
        }

        return equalsMap(splitWordsMap, wordsMap);
    }

    bool equalsMap(unordered_map<string, int> &a, unordered_map<string, int> &b) {
        for (auto &key_and_value: a) {
            const string &key = key_and_value.first;
            int value = key_and_value.second;
            if (b.find(key) == b.end() || b[key] != value) {
                return false;
            }
        }

        for (auto &key_and_value: b) {
            const string &key = key_and_value.first;
            int value = key_and_value.second;
            if (a.find(key) == a.end() || a[key] != value) {
                return false;
            }
        }

        return true;
    }

    unordered_map<string, int> wordsMap;
};

int main() {
    Solution s;
    string str = "barfoothefoobarman";

    vector<string> words{"foo", "bar"};
    vector<int> res = s.findSubstring2(str, words);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}
