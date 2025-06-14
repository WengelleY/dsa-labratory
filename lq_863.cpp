#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;



 struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public :
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
{ unordered_map<TreeNode*, TreeNode*> childToParent;
queue<TreeNode*> my_q;
my_q.push(root);
while(!my_q.empty()){
      TreeNode* node = my_q.front();
           my_q.pop();
      if (node->left){
          childToParent[node->left] = node;
             my_q.push (node->left);
            }
     if (node->right){
        childToParent[node->right] = node;
            my_q. push(node->right);
     }
    }




    int level = 0;
queue<pair<TreeNode*, TreeNode*>> transversal; 
transversal.push({target, NULL});


while(!transversal. empty()){

int nodesCount = transversal.size();
    vector<int>  soln;
           while(nodesCount-- ){
        TreeNode* node = transversal.front().first;
        TreeNode* src = transversal.front().second;
        transversal.pop();
      
       if (node->left && node->left != src) transversal.push({node->left, node}); 
       if (node->right && node->right != src) transversal.push({node->right, node});
       if (childToParent.find(node)   !=   childToParent.end()   &&  childToParent[node] != src)
            transversal.push({childToParent[node], node});
            soln.push_back(node->val);

       }

       if(level == k) 
                return soln;
            

       level++;
    }
    return {};
   }
};
