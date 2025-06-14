#include <vector>
#include <queue>
using namespace std;

class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    const int path = grid.size();
     vector<vector<bool>> seen(path, vector<bool>(path));
     queue<pair<int, int>> my_q;

     if (grid[0][0] == 1 || grid.back().back() == 1)
      return -1;
       my_q.push({0,0});
       seen[0][0] = true;

    int ways = true;

    while(!my_q.empty()){
      int size = my_q.size();
    for(int i = 0; i < size; i++){
       auto high = my_q.front();
       int row = high.first;
       int col = high.second;
       my_q. pop();
if(row == path-1 && col == path-1) return ways;
for(int j=-1; j < 2;j++){
    for(int k = -1; k<2; k++){
      int hor = row+j;
      int ver = col+k;

      if(0 <= hor && hor < path && 0 <= ver && ver < path &&
      !seen[hor] [ver] && !grid[hor][ver]){
      my_q. push({hor, ver});
      seen[hor][ver] = 1;
      }
    }
  }
}
ways++;
    }
return -1;
  }
};