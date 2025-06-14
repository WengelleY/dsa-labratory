#include <vector>
#include <queue>
using namespace std;
class Solution

{
public:
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
int p = mat.size();
int q = mat[0].size();
vector<vector<int>> soln(p, vector<int>(q));
vector<vector<int>> seen(p, vector<int>(q,0));
queue<pair<pair<int, int>, int>> my_q;
for(int i=0;i<p; i++){
    for(int j=0;j<q;j++){
      if (mat [i] [j]==0){
          soln[i] [j]=0;
my_q.push({{i,j},0});
seen [i] [j]=1;
      }
    }

}
int r[] = {-1,0,1,0};
int c[] = {0,1,0,-1};
while(!my_q.empty()){
     int row = my_q.front().first.first;
     int col = my_q.front(). first.second;
      int count = my_q.front().second;
      my_q.pop();
      for(int i=0;i<4;i++){
             int colm = row +r[i];
             int coln = col +c[i];
             if(colm>=0&&colm<p&&coln>=0&&coln<q&&seen [colm] [coln] !=1){
                  soln[colm] [coln] = count+1;
                my_q.push ({{colm,coln},count+1});
            seen[colm][coln] =1;
     }
   }
}
return soln;
      }
    };
