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

vector<int> itreative_Inorder(TreeNode* root){

    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while(1){

        if(curr){
            s.push(curr);
            curr = curr->left;
        }
        else{

            if(s.empty()) break;
            
            curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            curr = curr->right;              
        }
    }

    return ans;
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

    vector<int> ans = itreative_Inorder(root);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
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