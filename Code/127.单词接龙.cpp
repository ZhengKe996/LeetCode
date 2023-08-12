/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
 private:
  unordered_set<string> wordSet;
  unordered_map<string, int> depth;
  unordered_map<string, int> depthBegin, depthEnd;
  queue<string> q;
  queue<string> qBegin, qEnd;

 public:
  /**
   * 折半搜索优化(64ms)
   */
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // 加入所有节点，访问过一次，删除一个。
    unordered_set<string> s;
    for (auto& i : wordList) s.insert(i);

    queue<pair<string, int>> q;
    // 加入beginword
    q.push({beginWord, 1});

    string tmp;  // 每个节点的字符
    int step;    // 抵达该节点的step

    while (!q.empty()) {
      if (q.front().first == endWord) {
        return (q.front().second);
      }
      tmp = q.front().first;
      step = q.front().second;
      q.pop();

      // 寻找下一个单词了
      char ch;
      for (int i = 0; i < tmp.length(); i++) {
        ch = tmp[i];
        for (char c = 'a'; c <= 'z'; c++) {
          // 从'a'-'z'尝试一次
          if (ch == c) continue;
          tmp[i] = c;
          // 如果找到的到
          if (s.find(tmp) != s.end()) {
            q.push({tmp, step + 1});
            s.erase(tmp);  // 删除该节点
          }
          tmp[i] = ch;  // 复原
        }
      }
    }
    return 0;
  }
  /**
   * 折半搜索优化(存在问题)
   */
  int ladderLength3(string beginWord, string endWord,
                    vector<string>& wordList) {
    for (string& s : wordList) wordSet.insert(s);
    if (wordSet.find(endWord) == wordSet.end()) return 0;

    depthBegin[beginWord] = 1;
    depthEnd[endWord] = 1;
    qBegin.push(beginWord);
    qEnd.push(endWord);
    // 两边轮流扩展，每次各走一步。当某一次相遇时 两块架起来就是答案 层数减半
    while (!qBegin.empty() || !qEnd.empty()) {
      int res = expand(qBegin, depthBegin, depthEnd);
      if (res != -1) return res;
      res = expand(qEnd, depthEnd, depthBegin);
      if (res != -1) return res;
    }
    return 0;
  }

  int expand(queue<string>& q, unordered_map<string, int>& depth,
             unordered_map<string, int>& depthOther) {
    if (q.empty()) return -1;
    string s = q.front();
    q.pop();
    for (int i = 0; i < s.length(); i++) {
      for (char ch = 'a'; ch <= 'z'; ch++) {
        if (ch == s[i]) continue;
        string ns = s;
        ns[i] = ch;
        if (wordSet.find(ns) == wordSet.end()) continue;
        if (depth[ns] != 0) continue;
        if (depthOther[ns] != 0) return depth[s] + depthOther[ns];
        depth[ns] = depth[s] + 1;
        q.push(ns);
      }
    }
    return -1;
  }

  /**
   * 未进行折半搜索   (124 ms)
   */
  int ladderLength2(string beginWord, string endWord,
                    vector<string>& wordList) {
    for (string& s : wordList) wordSet.insert(s);
    if (wordSet.find(endWord) == wordSet.end()) return 0;
    depth[beginWord] = 1;
    q.push(beginWord);
    while (!q.empty()) {
      string s = q.front();
      q.pop();
      for (int i = 0; i < s.length(); i++) {
        for (char ch = 'a'; ch <= 'z'; ch++) {
          if (ch == s[i]) continue;
          string ns = s;
          ns[i] = ch;
          if (wordSet.find(ns) == wordSet.end()) continue;
          if (depth[ns] != 0) continue;
          depth[ns] = depth[s] + 1;
          q.push(ns);
          if (ns == endWord) return depth[ns];
        }
      }
    }
    return 0;
  }
};
// @lc code=end
