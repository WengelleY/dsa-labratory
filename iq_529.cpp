#include <vector>
#include <tuple>
#include <functional>

using namespace std;
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        const int row = click[0], col = click[1];
        const int nrows = board.size(), ncols = board[0].size();
        vector<vector<char>> bro = board;
        vector<vector<int>> bro_mine_num(nrows, vector<int>(ncols,0));

        const vector<tuple<int,int>> dirs = {
            make_tuple(-1,-1),
            make_tuple(-1,0),
            make_tuple(-1,1),
            make_tuple(0,-1),
            make_tuple(0,1),
            make_tuple(1,-1),
            make_tuple(1,0),
            make_tuple(1,1)
        };

        auto boos = [&nrows,&ncols](const int& r, const int& c) {
            return (r >= 0 && r < nrows && c >= 0 && c < ncols);
        };

        auto mine_count = [&](const int& r, const int& c) {
            int ret = 0;
            for(const auto& dir : dirs) {
                int nr = r + get<0>(dir), nc = c + get<1>(dir);
                if(boos(nr,nc) && bro[nr][nc] == 'M') ret++;
            }
            return ret;
        };

        for(int r = 0; r < nrows; ++r) {
            for(int c = 0; c < ncols; ++c) {
                bro_mine_num[r][c] = mine_count(r,c);
            }
        }

        function<void(int,int)> dfs = [&](int r, int c) {
            if(!boos(r,c)) return;
            if(bro[r][c] == 'M') return;
            if(bro[r][c] != 'E') return;
            
            if(bro_mine_num[r][c] > 0) {
                bro[r][c] = '0' + bro_mine_num[r][c];
                return;
            }

            bro[r][c] = 'B';
            for(const auto& dir : dirs) {
                dfs(r + get<0>(dir), c + get<1>(dir));
            }
        };

        if(bro[row][col] == 'M') {
            bro[row][col] = 'X';
            return bro;
        }

        dfs(row,col);
        return bro;
    }
};