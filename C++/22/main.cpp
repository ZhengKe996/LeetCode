#include <iostream>


using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0)return {""};
        if (store.find(n) != store.end()) return store[n];

        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            vector<string> A = generateParenthesis(i - 1);
            vector<string> B = generateParenthesis(n - i);
            for (string &a: A) {
                for (string &b: B) {
                    ans.push_back("(" + a + ")" + b);
                }
            }
        }
        store[n] = ans;
        return ans;
    }

private:
    unordered_map<int, vector<string>> store;
};

int main() {
    return 0;
}
