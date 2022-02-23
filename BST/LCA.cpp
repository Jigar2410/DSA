#include<bits/stdc++.h>
using namespace std;

struct TreeNode{

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){

        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    if(root == NULL) return root;
    
    if(p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left,p,q);
    if(p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right,p,q);
    
    return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    if(root == NULL) return root;
    
    while(root){
        
        if(p->val < root->val && q->val < root->val) root = root->left;
        else if(p->val > root->val && q->val > root->val) root = root->right;
        else
            return root;
    }
    return root;
}



int main(){

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(12);
    root->right->right->left = new TreeNode(11);
    root->right->right->right = new TreeNode(14);


    /*
                    
                   8
                  / \ 
                 6   9
                /  \  \       
               4    7  12  
              /        / \
             1        11  14                           
 
    */
    return 0;
}