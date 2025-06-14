#include <vector>
#include <queue>
#include <set>
using namespace std;
class solution { 
public:
bool canVisitAllRooms(vector<vector<int>>& rooms){
    set <int> seen;
    queue<int> my_q;


my_q.push(0);
while(!my_q. empty()) {
    int q_size = my_q.size();
    for(int i = 0; i < q_size; i++){

           int roomnow = my_q.front();
           my_q.pop();
        seen. insert (roomnow);
        vector<int> keys = rooms [roomnow];
         for(int j = 0; j < keys. size(); j++){
            if(seen. find (keys[j]) == seen.end()){

               my_q. push (keys [j]);
            }
        }
    }
}
return seen.size() == rooms. size();
}
};