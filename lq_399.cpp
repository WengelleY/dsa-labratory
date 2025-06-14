#include <unordered_map>  
#include <vector>         
#include <string>         
#include <utility>        
using namespace std;






class Solution {
public:
    void dfs(string s, string d, unordered_map<string,vector<pair<string,double>>> mp, unordered_map<string,int> &seen,double &soln,double temp)
    {
        if(seen.count(s))
        {
            return;
        }
        if(s==d)
        {
            soln=temp;
            return;
        }
        seen[s]=1;
        for(auto x:mp[s])
        {
            dfs(x.first,d,mp,seen,soln,temp*x.second);
        }
        return;
    }
     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mp;

                     for (int i = 0; i < equations.size(); i++) {
                            mp[equations[i][0]].push_back({equations[i][1], values[i]});
                            mp[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
                    vector<double>  finals;

                    for (int i = 0; i < queries.size(); i++) {
                            string source = queries[i][0];
                            string destination = queries[i][1];

                            unordered_map<string, int> visited;
                                    double ans = -1.0;
                                    double temp = 1;
                                    if(mp.count(source))
                                     dfs(source, destination, mp, visited, ans, temp);
                                    finals.push_back(ans);
                    }
                    return finals;
                }
            };

