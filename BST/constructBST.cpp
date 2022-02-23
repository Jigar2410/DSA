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

TreeNode* construct(vector<int>& preorder, int &i,int upperBound){
        
    if(i==preorder.size() || preorder[i] > upperBound) 
        return NULL;
    
    TreeNode* root = new TreeNode(preorder[i++]);
    root->left = construct(preorder,i,root->val);
    root->right = construct(preorder,i,upperBound);
    
    return root;
    
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    
    int i = 0;
    return construct(preorder,i,INT_MAX);
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