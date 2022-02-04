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

vector<vector<int>> allInOneTraversal(TreeNode* root){

    vector<vector<int>> ans;
    vector<int> pre,in,post;
    if(!root) return ans;
    stack<pair<TreeNode*,int>> s;
    s.push({root,1});
    while(!s.empty()){

        auto curr = s.top();
        s.pop();
        TreeNode* tmp = curr.first;
        int i = curr.second;

        // this is part of preorder 
        // increment 1 to 2 and 
        // push left
        if(i==1){
            pre.push_back(tmp->val);
            s.push({tmp,2});
            if(tmp->left) s.push({tmp->left,1});
        }
        // this is part of inorder 
        // increment 2 to 3 and 
        // push right
        else if(i==2){
            in.push_back(tmp->val);
            s.push({tmp,3});
            if(tmp->right) s.push({tmp->right,1});
        }

        // don't push it back again 
        else
            post.push_back(tmp->val);
    }

    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);

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

    vector<vector<int>> ans = allInOneTraversal(root);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
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
}//4 10 14 8 15 9 5 2 6 13 11 12 7 3 1 