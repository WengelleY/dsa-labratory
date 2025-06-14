#include <vector>


using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        int H = grid.size();
        int L = grid[0].size();
        if(grid[r][c] != 'O') return;

        grid[r][c] = 'Z';
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        for(int i = 0; i < 4; i++)
        {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if(rr >= 0 && rr < H && cc >= 0 && cc < L)
            {
                 dfs(grid, rr, cc);
            }
        }
    }
          
void solve(vector<vector<char>>& grid) {
    int R = grid.size();
    int C = grid[0].size();
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(i == 0 || j == 0 || i == R-1 || j == C-1)
            {
                dfs(grid, i, j);
            }
        }
    }
    for(int i = 0; i < R; i++){
         for(int j = 0; j < C; j++){
            if(grid[i][j] == 'Z'){
                grid[i][j] ='O';
            }
            else if (grid[i][j] == 'O'){
                grid[i][j] = 'X';
            }
        }
    }
}
};