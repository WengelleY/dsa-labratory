#include <vector>
using namespace std;
class Solution {
public:
int maxArea = 0;
   void holl(vector<vector<int>>& grid, int h, int l, int &newk) {
        if (h < 0 || l >= grid.size() || l < 0 || l >= grid[0].size() || !grid[h][l])
            return;

        grid[h][l] = 0;
        newk++;
        maxArea = max(maxArea, newk);
        holl(grid, h - 1, l, newk);
        holl(grid, h + 1, l, newk);
        holl(grid, h, l - 1, newk);
        holl(grid, h, l + 1, newk);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int newk;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    newk = 0;
                    holl(grid, i, j, newk);
                }
            }
        }
        return maxArea;
    }
};