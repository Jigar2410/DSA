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

bool isValid(TreeNode* root,long long lowerBound,long long upperBound){
        
    if(!root) return true;
    
    return (root->val > lowerBound && root->val < upperBound)
        && isValid(root->left,lowerBound,root->val)
        && isValid(root->right,root->val,upperBound);
}
bool isValidBST(TreeNode* root) {
    
    return isValid(root,LLONG_MIN,LLONG_MAX);
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