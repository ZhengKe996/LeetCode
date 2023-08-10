#include <iostream>

using namespace std;

class Trie {
 private:
  struct Node {
    int count;
    vector<Node*> child;
    Node() {
      count = 0;
      child.resize(26);
    };
  };
  Node* root;
  bool find(string s, bool isInsert, bool isPrefix) {
    Node* curr = root;

    for (char ch : s) {
      if (curr->child[ch - 'a'] == nullptr) {
        if (isInsert)
          curr->child[ch - 'a'] = new Node();
        else
          return false;
      }
      curr = curr->child[ch - 'a'];
    };
    if (isInsert) curr->count++;
    if (isPrefix) return true;
    return curr->count > 0;
  }

 public:
  Trie() { root = new Node(); }

  void insert(string word) { find(word, true, false); }

  bool search(string word) { return find(word, false, false); }

  bool startsWith(string prefix) { return find(prefix, false, true); }
};
