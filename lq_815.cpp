#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0; 
        
        unordered_map<int, vector<int>> stop;
        for(int i=0; i<routes.size();i++){
            int bId = i;
            vector<int> bStops = routes[i];
            for(auto bStop : bStops){
                stop[bStop].push_back(bId);
            }
        }

        queue<pair<int, int>> my_q;
        unordered_map<int, bool> bVis, stops;
        my_q.push({source, 0});
        stops[source] = true;

        while(!my_q.empty()){
            int sz = my_q.size();
            while(sz--){
                pair<int, int> p = my_q.front();
                my_q.pop();

                int curStop = p.first;
                int busTravelled = p.second;

                if(curStop == target) return busTravelled;
                for(auto bus : stop[curStop]){
                    if(bVis[bus]) continue;
                    bVis[bus] = true; 
                    for (auto busStop : routes[bus]) {
                        if(stops[busStop]) continue;
                        stops[busStop] = true;
                        my_q.push({busStop, busTravelled+1});
                    }
                }
            }
        }
        return -1;
    }
};

                                         
                                        
