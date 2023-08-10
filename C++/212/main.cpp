#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
 private:
  const int dx[4] = {-1, 0, 0, 1};
  const int dy[4] = {0, -1, 1, 0};

  struct Node {
    int count;
    unordered_map<char, Node*> child;
    Node() : count(0){};
  };

  Node* root;
  int m, n;
  vector<vector<bool>> visit;
  string str;
  unordered_set<string> ans;

  void insert(const string& s) {
    Node* curr = root;
    for (char c : s) {
      if (curr->child.find(c) == curr->child.end()) curr->child[c] = new Node();
      curr = curr->child[c];
    }
    curr->count++;
  }

  void dfs(vector<vector<char>>& board, int x, int y, Node* curr) {
    if (curr == nullptr) return;
    char ch = board[x][y];
    if (curr->child.find(ch) == curr->child.end()) return;
    Node* next = curr->child[ch];

    str.push_back(ch);
    if (next->count > 0) ans.insert(str);

    if (next->child.empty()) {
      curr->child.erase(ch);
      delete next;
    } else {
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        visit[nx][ny] = true;
        dfs(board, nx, ny, next);
        visit[nx][ny] = false;
      }
    }
    str.pop_back();
  }

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    // 1. 建立Trie 插入Words;
    root = new Node();
    for (const string& word : words) {
      insert(word);
    }

    // 2. 枚举每个起点，搜索
    m = board.size();
    n = board[0].size();
    visit = vector<vector<bool>>(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        visit[i][j] = true;
        dfs(board, i, j, root);
        visit[i][j] = false;
      }
    }
    return vector<string>(ans.begin(), ans.end());
  }
};

class Solution2 {
 public:
  // 上下左右四个方向深搜检索单词word，使用取巧的方式，代码长度换减少判断
  bool dfsFindWord(vector<vector<char>>& board, int r, int c,
                   const string& word, int index) {
    // 若当前index = word.size - 1，则说明单词完全匹配，返回true
    if (index == word.size() - 1) {
      return true;
    }
    char temp = board[r][c], ch = word[++index];
    board[r][c] = 0;           // 标记当前节点已访问
    int new_r = 0, new_c = 0;  // 记录新行、列
    // 上
    new_r = r - 1;
    if (new_r >= 0 && board[new_r][c] == ch) {
      // 若找到单词，则直接返回
      if (dfsFindWord(board, new_r, c, word, index)) {
        board[r][c] = temp;
        return true;
      }
    }
    // 下
    new_r = r + 1;
    if (new_r < board.size() && board[new_r][c] == ch) {
      // 若找到单词，则直接返回
      if (dfsFindWord(board, new_r, c, word, index)) {
        board[r][c] = temp;
        return true;
      }
    }
    // 左
    new_c = c - 1;
    if (new_c >= 0 && board[r][new_c] == ch) {
      // 若找到单词，则直接返回
      if (dfsFindWord(board, r, new_c, word, index)) {
        board[r][c] = temp;
        return true;
      }
    }
    // 右
    new_c = c + 1;
    if (new_c < board[0].size() && board[r][new_c] == ch) {
      // 若找到单词，则直接返回
      if (dfsFindWord(board, r, new_c, word, index)) {
        board[r][c] = temp;
        return true;
      }
    }
    board[r][c] = temp;
    return false;
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> result = {};  // 记录能匹配的单词
    unordered_map<char, vector<pair<int, int>>>
        indexs;  // 记录字符矩阵所有字符的矩阵下标
    int row = board.size(), col = board[0].size();
    // 字符矩阵元素存入map中
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        indexs[board[i][j]].emplace_back(i, j);
      }
    }
    // 遍历words中所有单词
    for (auto&& word : words) {
      bool flag = false;
      // 检查word所有字符是否字符矩阵中都能找到
      for (auto&& ch : word) {
        // 若找不到则直接搜索下一个单词
        if (indexs.find(ch) == indexs.end()) {
          flag = true;
          break;
        }
      }
      // 当前word中存在字符矩阵中找不到的字符，不再判别该单词
      if (flag) {
        continue;
      }
      string new_word = word;
      // 若当前单词长度前四个字母都相同，则翻转一下生成新单词，如：aaaab 变为
      // baaaa
      if (word.size() > 5 && word[0] == word[1] && word[1] == word[2] &&
          word[2] == word[3]) {
        reverse(new_word.begin(), new_word.end());
      }
      // 从word的第一个字符开始检索该单词，看能否找到。遍历map中所有该字符的坐标
      for (auto&& [r, c] : indexs[new_word[0]]) {
        if (dfsFindWord(board, r, c, new_word, 0)) {
          result.emplace_back(word);
          break;
        }
      }
    }
    return result;
  }
};

int main() {}