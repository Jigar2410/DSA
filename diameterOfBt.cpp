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

int dfs_height(TreeNode* root){

    if(!root) return 0;

    int lh = dfs_height(root->left);
    int rh = dfs_height(root->right);

    return 1+max(lh,rh);
}

int maxDiam = 0;
void diameter(TreeNode*root){

    if(!root) return;

    int lh = dfs_height(root->left);
    int rh = dfs_height(root->right);

    maxDiam = max(maxDiam,lh+rh);

    diameter(root->left);
    diameter(root->right);
}

int diameterV2(TreeNode* root, int& d){

    if(!root) return 0;

    int lh = diameterV2(root->left,d);
    int rh = diameterV2(root->right,d);

    d = max(d,lh+rh);

    return 1+max(lh,rh);
}

int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(17);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->left->right->left->left = new TreeNode(10);
    root->left->right->left->right = new TreeNode(14);
    root->left->right->right = new TreeNode(9);
    root->left->right->right->left = new TreeNode(15);
    root->right->left = new TreeNode(6);
    root->right->left->right = new TreeNode(16);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(11);
    root->right->right->left->right = new TreeNode(13);
    root->right->right->right = new TreeNode(12);


    diameter(root);
    cout<<maxDiam<<endl;
    int d = 0;
    diameterV2(root,d);
    cout<<d<<endl;
    // isBalancedV2(root) >= 0 ? cout<<1<<endl : cout<<0<<endl; 

    /*
                    
                    1
                  /   \ 
                 /     \
                /       \ 
               2         3
             /  \      /   \    
            4    5    6     7
           /    /  \   \   / \
         17    8    9  16 11  12
             / \   /        \
           10  14 15        13
 
    */
    return 0;
}