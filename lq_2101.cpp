#include <vector>


using namespace std;
class Solution {
public:
    #define ll long long
    void dfs(int src, vector<int>& seen, vector<int> adj[]) {
        seen[src] = 1;
        for(int x : adj[src]) {
            if(seen[x] == 0) {
                dfs(x, seen, adj);
            }
        }
    }
   
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n]; 
        for(int i = 0; i < n; i++) { 
            ll r1 = bombs[i][2]; 
            ll x1 = bombs[i][0]; 
            ll y1 = bombs[i][1]; 
            for(int j = 0; j < n; j++) { 
                if(i != j) { 
                    ll x2 = bombs[j][0]; 
                    ll y2 = bombs[j][1]; 
                    ll dsq = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2); 
                    if(dsq <= r1*r1) { 
                        adj[i].push_back(j); 
                    } 
                } 
            } 
        }
        vector<int> vis(n); 
        int ans = 0;

        for(int i = 0; i < n; i++) {
            dfs(i, vis, adj);
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(vis[j] == 1) cnt++;  
            }
            ans = max(ans, cnt);
            fill(vis.begin(), vis.end(), 0);
        }
        return ans;
    }
};