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


int findHeightLeft(TreeNode* root){
        
    int height = 0;
    while(root){
        height++;
        root = root->left;
    }
    return height;
}

int findHeightRight(TreeNode* root){
    
    int height = 0;
    while(root){
        height++;
        root = root->right;
    }
    return height;
}

// Time Complexity : O(log(N)*log(N)) 
int countNodes(TreeNode* root) {
    
    if(!root) return 0;
    
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);
    
    if(lh==rh) return (1<<lh)-1;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
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

    int ans = BURN(root,root->left->right,2);
    cout<<ans<<endl;
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