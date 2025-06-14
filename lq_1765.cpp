
#include <vector>
#include <queue>
#define INT_MAX 2147483647
using namespace std;

class Solution {

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int H = isWater.size();
        int L = isWater[0].size();
        vector<vector<int>>grid (H,vector<int>(L,INT_MAX));
        queue<pair<int,int>>my_q;

        for(int i = 0 ; i<H ;i++ ){
            for(int j = 0 ; j<L;j++){
                if(isWater[i][j]==1){
                    my_q.push({i,j});
                    grid[i][j]= 0 ;
                   } 
                }
            }
            while(!my_q.empty()){
                int h = my_q.front().first;
                int l = my_q.front().second  ;
                my_q.pop();
                int dh[4] = {0,0,-1,1} ;
                int dl[4] = {-1,1,0,0};
                for(int i = 0 ; i<4;i++){
                    int hh = h+ dh[i];
                    int ll = l + dl[i];
                 if(hh>=0 && hh<H &&  ll>=0 &&  ll < L && grid[hh][ll]>1+grid[h][l])
                 {
                    grid [hh][ll] = 1+grid[h][l];
                    my_q.push({hh,ll});
                        }
                     }   
                 }
                 return grid;
        }
};