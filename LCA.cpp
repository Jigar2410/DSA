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


TreeNode* LCAUtil(TreeNode*root,int p,int q){

    if(!root || root->val == p || root->val == q) return root;

    TreeNode* x = LCAUtil(root->left,p,q);
    TreeNode* y = LCAUtil(root->right,p,q);

    if(!x) return y;
    if(!y) return x;

    return root;
}

bool search(TreeNode*root,int x){

    if(!root) return false;

    return ((root->val == x) || search(root->left,x) || search(root->right,x)); 
}

int lca(TreeNode* root, int p, int q) {

    bool isP = search(root,p);
    bool isQ = search(root,q);

    if(isP && isQ) return LCAUtil(root,p,q)->val;

    return -1;
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
    root->right->left = new TreeNode(5);
    root->right->left->right = new TreeNode(16);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(11);
    root->right->right->left->right = new TreeNode(13);
    root->right->right->right = new TreeNode(12);


    /*
                    
                    1
                  /   \ 
                 /     \
                /       \ 
               2         3
             /  \      /   \    
            4    6    5     7
           /    /  \   \   / \
         17    8    9  16 11  12
             / \   /        \
           10  14 15        13
 
    */
    return 0;
}