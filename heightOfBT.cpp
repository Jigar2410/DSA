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

    return 1 + max(lh,rh);
}

int bfs_height(TreeNode* root){

    if(!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int height = 0;
    while(!q.empty()){

        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        height++;
    }
    return height;
}

int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->left->right->left->left = new TreeNode(10);
    root->left->right->left->right = new TreeNode(14);
    root->left->right->right = new TreeNode(9);
    root->left->right->right->left = new TreeNode(15);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(11);
    root->right->right->left->right = new TreeNode(13);
    root->right->right->right = new TreeNode(12);

    cout<<dfs_height(root)<<endl<<bfs_height(root)<<endl;

    /*
                  1
                /   \
               2      3
             /  \    / \    
            4    5  6   7
               /  \    / \
              8    9  11  12
             / \   /   \
           10  14 15   13
 
    */
    return 0;
}//4 10 14 8 15 9 5 2 6 13 11 12 7 3 1 