


#include <utility> 
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };








class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return length(root).first;
         }
         pair<TreeNode*, int > length(TreeNode* root){
            if(!root) return {root,0};
            auto low = length(root->left);
            auto r = length(root->right);
            if(low.second == r.second)  return {root, low.second+1};

            if(low.second > r.second)  return {low.first, low.second+1};
            return {r.first,r.second+1};
         


         }
};