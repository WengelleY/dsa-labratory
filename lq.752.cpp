
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;
class Solution {

public:
int openLock(vector<string>& deadends, string target) {
unordered_set<string> deads(deadends. begin(), deadends.end());
unordered_set<string> seen;
queue<string>  my_q;
my_q.push("0000");
int status = 0;
while(!my_q. empty()) {
    int size = my_q.size();
     for(int i = 0 ; i< size ; i++){
     string now =  my_q.front();
     my_q. pop();
    if(now == target) return status;
    if(deads. count(now) || seen.count(now))
      continue;
      seen. insert(now); 
      Lookset (now, my_q);
     }
status++;
}
return -1;
}
void Lookset(string str, queue<string>& my_q) {
for(int i = 0; i < 4; i++) {
char c = str[i];
str[i]= (c - '0' + 1) % 10 +'0';
my_q. push(str);
str[i]=(c - '0' - 1+10) % 10 + '0';
my_q.push(str);
str[i]= c;
}
}
};