
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
    void preOrder(TreeNode* root,  
                int& myReturn,
                int currentNumber) 
    {
        if (root == nullptr)
            return;
        currentNumber = currentNumber * 10 + root->val;  

        if (root->left == nullptr and root->right == nullptr) 
        {
            myReturn += currentNumber;
            return;
        }
        preOrder(root->left, myReturn, currentNumber);
        preOrder(root->right, myReturn, currentNumber);
    }

    int sumNumbers(TreeNode* root) {  
        if (root == nullptr)
            return 0;
        int myReturn {0};  
        preOrder(root, myReturn, 0);
        return myReturn;
    }
};