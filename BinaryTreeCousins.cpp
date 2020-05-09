/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.
*/
/*
 * Definition for a binary tree node.
 */
 #define NULL 0
 
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
    int getDepth(TreeNode* root, TreeNode* & parent, int x)
    {
        if (root == NULL)
            return -1;
        
        if (root->val == x)
        {
            return 0;
        }
        
        int val1 = getDepth(root->left,parent, x);

        if (val1 == 0)
        {
            parent = root;
            return 1 +val1;
        }
        else if (val1 != -1)
            return 1 + val1;
        
        int val2 = getDepth(root->right,parent, x);

        if (val2 == 0)
        {
            parent = root;
            return 1 + val2;
        }
        else if (val2 != -1)
            return 1 + val2;
        
        return -1;
        
    }
    
    bool isCousins(struct TreeNode* root, int x, int y) {
        
        struct TreeNode* parent1 = NULL;
        struct TreeNode*parent2 = NULL;
            
        int dep1 = getDepth(root, parent1, x);
        int dep2 = getDepth(root, parent2, y);
        
        //cout <<"parent1 val" << parent1->val;
        //cout <<"parent2 val" << parent2->val;
        if (dep1 == dep2)
        {
            if (parent1 == parent2)
                return false;
            
            return true;
        }
        else
            return false;
       
    }
};