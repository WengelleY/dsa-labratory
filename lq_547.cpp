#include <vector>
using namespace std;


class Solution {
public:
    void dfs(int i, vector<vector<int>> &neg, vector<bool> &seen) {
        seen[i] = true;
        for(auto x: neg[i]) {
            if(!seen[x]) dfs(x, neg, seen);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> neg(n);
        for(int i = 0 ; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j]) {
                    neg[i].push_back(j);
                    neg[j].push_back(i);
                }
            }
        }
    int count = 0;
        vector<bool> seen(n, false);
        for(int i = 0; i<n; i++) {
            if(!seen[i]) {
                count++;
                dfs(i, neg, seen);
            }
        }
        return count;
    }
};
        
    