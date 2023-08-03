#include <iostream>

using namespace std;

class Solution {
private:
    string digits;
    string str;
    vector<string> ans;
    unordered_map<char, string> alphabet;

    void dfs(int index, string str) {
        if (index == digits.length()) {
            ans.push_back(str);
            return;
        }
        for (char ch: alphabet[digits[index]]) {
            dfs(index + 1, str + ch);
        }
    }

    void dfs2(int index) {
        if (index == digits.length()) {
            ans.push_back(str);
            return;
        }
        for (char ch: alphabet[digits[index]]) {
            str.push_back(ch);
            dfs2(index + 1);
            str.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        alphabet['2'] = "abc";
        alphabet['3'] = "def";
        alphabet['4'] = "ghi";
        alphabet['5'] = "jkl";
        alphabet['6'] = "mno";
        alphabet['7'] = "pqrs";
        alphabet['8'] = "tuv";
        alphabet['9'] = "wxyz";
        if (digits.empty()) return {};
        dfs(0, "");
        return ans;
    }

    /**
     * 优化空间
     * @param digits
     * @return
     */
    vector<string> letterCombinations2(string digits) {
        this->digits = digits;
        alphabet['2'] = "abc";
        alphabet['3'] = "def";
        alphabet['4'] = "ghi";
        alphabet['5'] = "jkl";
        alphabet['6'] = "mno";
        alphabet['7'] = "pqrs";
        alphabet['8'] = "tuv";
        alphabet['9'] = "wxyz";
        if (digits.empty()) return {};
        dfs2(0);
        return ans;
    }
};

int main() {
    return 0;
}
