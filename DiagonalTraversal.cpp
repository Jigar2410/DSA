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


// Here if 2 or more Tree nodes shares the same diagonal level then it will 
// output in pre-order style means first left subtree then right subtree
void diagonalRecursive(TreeNode* root, int diagonal, map<int,vector<int>>&mp){

    if(!root) return;

    mp[diagonal].push_back(root->val);
    diagonalRecursive(root->left,diagonal+1,mp);
    diagonalRecursive(root->right,diagonal,mp);

}

// If 2 or more Tree Nodes shares the same diagonal level then the 
// order will be for that level from left to right
vector<vector<int>> diagonalOrderTraversal(TreeNode* root){

    vector<vector<int>> ans;
    if(!root) return ans;
    map<int,vector<int>> mp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr = q.front().first;
            int diagonal = q.front().second;
            q.pop();

            mp[diagonal].push_back(curr->val);

            if(curr->left) q.push({curr->left,diagonal+1});
            if(curr->right) q.push({curr->right,diagonal});
        }
    }

    for(auto x : mp){
        ans.push_back(x.second);
    }

    return ans;
}

int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(17);
    root->left->right = new TreeNode(6);
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

    vector<vector<int>> v = diagonalOrderTraversal(root);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;      
    }  

    cout<<endl<<endl; 

    vector<vector<int>> ans;
    map<int,vector<int>> mp;
    diagonalRecursive(root,0,mp);
    for(auto x : mp){
        ans.push_back(x.second);
    }

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;      
    }

    cout<<endl<<endl; 
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