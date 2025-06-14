#include <vector>
using namespace std;
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
class Solution {
public:
int ImportanceSum=0;
      void AddSum(vector<Employee*>employees, int id){
            for(int i=0;i<employees.size();i++)
{if(employees[i]->id == id)
          {
                    ImportanceSum += employees[i]->importance;
                    if(employees[i] ->subordinates.size()==0)
                               return;
                    for(int j=0;j<employees[i] ->subordinates.size();j++)
                       AddSum(employees, employees[i] ->subordinates[j]);
}
}
      }


int getImportance(vector<Employee*> employees, int id) {
      AddSum(employees, id);
       return ImportanceSum;
}
};