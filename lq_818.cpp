
#include <vector> 
#include <cmath>    
#include <algorithm>
using namespace std;



class Solution{
public:
  int racecar(int target){

       vector<int> run(target+1,-1);
       return solve(target,run);
  }
  int solve(int target, vector<int>& run){
      if(run[target] != -1){
         return run [target];
      }


      int n=floor(log2(target))+1;
      if((1<<n)-1==target){
            return n;
      }
      run[target] =n+1+solve((1<<n)-1-target,run);
      for(int i=0;i<n-1;i++){
          run[target]=min(run[target],n+i+1+solve(target-(1<<(n-1))+(1<<i),run));
      }
      return run[target];
    }
};