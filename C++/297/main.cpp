#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    // 数字转成字符串，INT_MIN被转为空记号"n"
    string num2str(int x) {
        if (x == 0) return "0";
        if (x == INT_MIN) return "n";
        string res = "";
        bool mflag = false;
        if (x < 0) {
            mflag = true;
            x = -x;
        }
        while (x > 0) {
            res += (char) (x % 10) + 48;
            x /= 10;
        }
        if (mflag)
            res += '-';
        reverse(res.begin(), res.end());
        return res;

    }

    // 字符串转成数字，空记号"n"被转成INT_MIN
    int str2num(string s) {
        if (s == "n") return INT_MIN;
        if (s == "0") return 0;
        bool mflag = false;
        int x = 0;
        if (s[0] == '-') {
            mflag = true;
            s = s.substr(1, s.length());
        }
        for (auto &c: s) {
            x *= 10;
            x += c - 48;
        }
        if (mflag) x = -x;
        return x;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        queue<TreeNode *> q;
        if (!root) return "";
        string ans;

        // BFS遍历所有节点(包括虚拟空节点)
        q.push(root);
        while (!q.empty()) {
            int nowlen = q.size();
            int cnt = 0;
            int numcnt = 0;
            // 遍历当前层
            for (int i = 0; i < nowlen; i++) {
                TreeNode *now = q.front(); // 出队，取出当前节点
                q.pop();
                // 将当前节点值转成字符串加入结果中
                ans += num2str(now->val);
                ans += ',';
                if (now->val != INT_MIN) { // 如果当前节点非空，则将其子节点入队
                    numcnt++;
                    if (now->left) q.push(now->left);
                    else {
                        q.push(new TreeNode(INT_MIN));
                        cnt++;
                    } // 没有子节点则虚拟一个空节点
                    if (now->right) q.push(now->right);
                    else {
                        q.push(new TreeNode(INT_MIN));
                        cnt++;
                    } // 没有子节点则虚拟一个空节点
                }
            }
            if (cnt >= numcnt * 2) break; // 若当前层节点数量乘以2等于下一层虚拟空节点的数量，
            // 则说明下一层没有有效节点了，退出遍历
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.length() == 0) return NULL;
        int n = data.length();
        vector<int> nodes;
        int j = 0, k = 0;
        // 分割序列并将结果转换数字数组，存入nodes中。同样INT_MIN代表空
        while (k < n) {
            while (k < n && data[k] != ',') {
                k++;
            }
            nodes.emplace_back(str2num(data.substr(j, k - j)));
            k++;
            j = k;
        }
        queue<TreeNode *> q;
        n = nodes.size();
        int i = 1; // 标记当前遍历到哪个节点值了
        TreeNode *root = new TreeNode(nodes[0]);
        q.push(root);
        // BFS重构树
        while (!q.empty()) {
            if (i >= n) break;
            TreeNode *now = q.front();
            q.pop();
            // 当前节点的左右子节点值必然是nodes[i]与nodes[i+1]
            if (nodes[i] != INT_MIN) { // 将有效节点入队，有效节点才可能有子节点
                now->left = new TreeNode(nodes[i]); // 连接左子节点
                q.push(now->left);
            }
            i++;
            if (nodes[i] != INT_MIN) { // 将有效节点入队
                now->right = new TreeNode(nodes[i]); // 连接右子节点
                q.push(now->right);
            }
            i++; // 增加i
        }
        return root;
    }
};

int main() {
    return 0;
}
