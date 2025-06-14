#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> march;
       int r = grid.size(), c = grid[0].size(), fresh = 0, t = 0;
       for(int i = 0; i < r; ++i){
          for(int j = 0; j < c; ++j){
                if(grid[i][j] == 2) march.push({i, j});
                     else if(grid[i][j] == 1) fresh++;
          }
        }
    

while(!march. empty()){
     int num = march.size();
    for(int i = 0; i < num; ++i){
    int x = march. front().first, y = march.front().second;
    march.pop();
if(x > 0 && grid[x-1][y] == 1){ grid[x-1][y] = 2; fresh--; march.push({x-1, y});};
if(y > 0 && grid[x][y-1] == 1){ grid[x][y-1] = 2; fresh--; march.push({x, y-1});};
if(x < r-1 && grid[x+1][y] == 1){ grid[x+1][y] = 2; fresh--; march.push({x+1, y});};
if(y < c-1 && grid[x][y+1] == 1){ grid[x][y+1] = 2; fresh--; march.push({x, y+1});};
    }
if(!march. empty()) t++;
}
return (fresh == 0) ? t : -1;
    }
};