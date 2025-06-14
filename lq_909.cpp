#include <vector>
#include <queue>
#include <climits>
using namespace std;
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int snake = board.size();
        vector<int>b(snake*snake, -1); 
        int cnt = 0;
        for (int i = snake - 1; i >= 0; i--) {
            if ((snake - 1 - i) % 2 == 0) { 
             for (int j = 0; j < snake && cnt < b.size(); j++) {
                   if (board[i][j] != -1){
                        b[cnt] = board[i][j]-1 ;
                   }
                    cnt++;
                }
            } else {
                 for (int j = snake-1; j >= 0 && cnt < b.size(); j--) {
                       if (board[i][j] != -1) {
                           b[cnt] = board[i][j] - 1;
                       }
                        cnt++;
                    }
                }
        }
vector<int>dis(snake*snake, INT_MAX); 
queue <int> my_q;
my_q.push(0);
dis[0]=0;

                
while (!my_q.empty()) {
    int curr = my_q.front(); my_q.pop();
    for (int i = 1; i <= 6 && curr+ i < b.size(); i++) {
            int next = b[curr+i] != -1 ? b[curr+i] : (curr+i);
            if (dis[next] == INT_MAX) {
                   dis[next] = dis[curr] + 1;
                   my_q.push (next);


                   if (next == snake * snake - 1) {
                        return dis[next];
            }
        }
    }
}
return (dis[snake*snake-1] == INT_MAX ) ? -1 : dis[snake*snake -1];


        
}
};