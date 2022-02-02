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

vector<vector<int>> levelorder(TreeNode* root){

    vector<vector<int>> res;

    if(!root) return res;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){

        int size = q.size();
        vector<int> temp;

        for(int i=0;i<size;i++){

            TreeNode* curr = q.front();
            q.pop();

            temp.push_back(curr->val);

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    
        res.push_back(temp);
    } 

    return res;
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

    vector<vector<int>> v = levelorder(root);

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

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
}