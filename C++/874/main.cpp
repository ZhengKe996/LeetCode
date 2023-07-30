#include <iostream>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
        unordered_set<long long> obs; // 障碍物
        for (const vector<int> &obstacle: obstacles) {
            obs.insert(calcHash(obstacle));
        }
        int x = 0, y = 0;
        int dir = 0;// N=0,E=1,S=2,W=3;(dir+1)%4 右转 (dir+3)%4 左转;

        // 网格中行走题目,技巧：方向数组
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        int ans = 0;
        for (int command: commands) {
            if (command == -1) {
                dir = (dir + 1) % 4;
            } else if (command == -2) {
                dir = (dir + 3) % 4;
            } else {
                for (int i = 0; i < command; i++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    // 如果是障碍物
                    if (obs.find(calcHash({nx, ny})) != obs.end()) {
                        break;
                    }

                    x = nx, y = ny;
                    ans = max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }

private:
    long long calcHash(const vector<int> &obstacle) {
        return (obstacle[0] + 30000) * 60001ll + (obstacle[1] + 30000);
    }
};

int main() {
    return 0;
}
