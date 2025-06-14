#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    

     const vector<int> dH={0,0,-1,1};
     const vector<int> dL={-1,1,0,0};
    int maxDistance(vector<vector<int>>& grid) {
     int h=grid.size();
     int l=grid[0].size();
     queue<pair<int,int>>  my_q;
     for(int i=0;i<h;i++){
          for(int j=0;j<l;j++){
               if(grid[i][j]==1){
                  my_q.push({i,j});
                     grid[i][j]=2;
               }
            }
        }
if(my_q.size()==h*l || my_q.empty()) return -1;
   int greater=0;
while(!my_q. empty() ){
     int amt=my_q.size();
       while (amt--){
        auto node= my_q. front();
             my_q. pop();
             for (int i=0;i<4;i++){
             int next_a=node.first+dH[i];
             int next_b=node. second+dL[i];
             if((next_a   >=0 &&  next_b>=0) && (next_a<h && next_b<l)){
                  if(grid[next_a][next_b]==0){
                  my_q.push({next_a,next_b});
                     grid[next_a][next_b]=2;  
                  }
                }
            }
        }
        greater++;
    }
    return greater -1;
    }
};    