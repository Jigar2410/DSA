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


void mapParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&mp){
        
    if(!root) return;
    
    if(root->left) mp[root->left] = root;
    if(root->right) mp[root->right] = root;
    
    mapParent(root->left,mp);
    mapParent(root->right,mp);
}
int BURN(TreeNode* root, TreeNode* target, int k) {

    if(!root) return -1;
    unordered_map<TreeNode*,TreeNode*> parent_map;
    unordered_map<TreeNode*,bool> vis;
    mapParent(root,parent_map);
    queue<TreeNode*> q;
    q.push(target);
    vis[target] = true;
    int level = -1;
    while(!q.empty()){
        
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left && !vis[curr->left]) q.push(curr->left), vis[curr->left] = true;

            if(curr->right && !vis[curr->right]) q.push(curr->right),vis[curr->right] = true;
                                           
            if(parent_map[curr] && !vis[parent_map[curr]]) q.push(parent_map[curr]),vis[parent_map[curr]] = true;    
        }
        level++;
    }
    return level;
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