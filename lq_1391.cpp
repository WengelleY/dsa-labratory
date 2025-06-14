#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
bool isConnected(vector<vector<int>>& direct, int prev_street_type, int b, int a) {
        int way = prev_street_type * 2;
        for (int i = 0; i < 2; ++i) {
            int back = direct[way + i][0];
            int face = direct[way + i][1];
            if (back == b && face == a) {
                return true;
            }
        }
        return false;
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
       
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> direct{
            {0, -1}, {0, 1},  
            {-1, 0}, {1, 0},   
            {0, -1}, {1, 0},   
            {0, 1}, {1, 0},     
            {0, -1}, {-1, 0},
            {0, 1}, {-1, 0}
        };
        queue<int> my_q;
        unordered_set<int> seen;
        my_q.push(0);
        seen.insert(0);

    while (!my_q.empty()) {
        int next = my_q.front();
        my_q.pop();
        int y = next / c;
        int x = next % c;
        if (y == r - 1 && x == c - 1) {
            return true;
    }

         int val = grid[y][x] - 1;
         int street = val * 2;
         for (int i = 0; i < 2; ++i) {
             int dy = y + direct[street + i][0];
             int dx = x + direct[street + i][1];
             if (dy >= 0 && dy < r && dx >= 0 && dx < c &&
                !seen.count(dy * c + dx) &&
                isConnected(direct, grid[dy][dx] - 1,
                       -direct[street + i][0],
                       -direct[street + i][1])) {
                seen.insert(dy * c + dx);
                my_q.push(dy * c + dx);
        }
    }
}

return false;
    }
};