#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
private:
    unordered_map<string, int> depth;
    unordered_set<string> hashBank;
public:
    int minMutation(string startGene, string endGene, vector<string> &bank) {
        depth[startGene] = 0;
        for (string &seq: bank) hashBank.insert(seq);
        if (hashBank.find(endGene) == hashBank.end()) return -1;
        queue<string> q;
        q.push(startGene);
        const char gene[4] = {'A', 'C', 'G', 'T'};
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if (s[i] != gene[j]) {
                        string ns = s; // 暂存s
                        ns[i] = gene[j];
                        if (hashBank.find(ns) == hashBank.end())continue;
                        // 每个点只访问一次，第一次就是最少层数
                        if (depth.find(ns) != depth.end())continue;
                        depth[ns] = depth[s] + 1;
                        q.push(ns);
                        if (ns == endGene) return depth[ns];
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    string start = "AACCGGTT", end = "AACCGGTA";
    vector<string> bank = {"AACCGGTA"};
    int ans = s.minMutation(start, end, bank);
    cout << ans << endl;

    start = "AACCGGTT", end = "AAACGGTA", bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    ans = s.minMutation(start, end, bank);
    cout << ans << endl;

    start = "AAAAACCC", end = "AACCCCCC", bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
    ans = s.minMutation(start, end, bank);
    cout << ans << endl;

    return 0;
}
