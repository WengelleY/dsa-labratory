#include <vector>

using namespace std;

class Solution {
     public:
int back(vector<vector<char>> &snake, vector<int> &ent, int i, int j,
int n, int m ,  vector <vector<vector<int>>> &dp, int dir){
        if ((i == n-1 || j ==m-1 || i==0  || j==0) && (i!=ent[0]  || j!=ent[1]))
return 0;
if(dir != -1 && dp[i][j][dir] != -1)   return dp[i][j][dir];
        int del[] = {-1, 0, 1, 0, -1};
        int ans = 1e5;
        for(int ind = 0; ind<4; ind++){
            int nr = i+del[ind];
            int nc = j+del[ind+1];
            if(nr>=0 && nc>=0 && nr<=n-1 && nc<=m-1 &&(ent[0]!=nr || ent[1]!=nc) && snake[nr][nc]=='.'){
                snake[nr][nc] = '+';
                int res ;
                if (dp[nr][nc][ind]!=-1) res =1 +dp[nr][nc][ind];
                else res = 1 + back(snake, ent, nr, nc, n, m ,dp ,ind);
                ans = min(ans, res);
                snake[nr][nc] = '.';
            }
        }
        if(dir != -1) return dp[i][j][dir] = ans;
        else 
    
        return ans;


    }
int nearestExit (vector<vector<char>>& maze, vector<int>& entrance) {
       int n = maze.size();
       int m = maze[0].size();
       vector<vector<vector<int>>> dp(n, vector<vector<int>> (m,vector<int> (5, -1)));
        int ans = back(maze, entrance, entrance[0], entrance[1], n, m, dp,-1);
        return ans > 1e4 ? -1: ans ;
}
};


