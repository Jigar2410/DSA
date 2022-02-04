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

// Using 2 stack | Using 1 stack and reverse the vector
vector<int> itreative_postorder(TreeNode* root){

    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        TreeNode*curr = s1.top();
        s1.pop();
        
        //s2.push(curr);
        ans.push_back(curr->val);

        if(curr->left) s1.push(curr->left);
        if(curr->right) s1.push(curr->right);
    }

    // while(!s2.empty()){
    //     TreeNode* curr = s2.top();
    //     s2.pop();
    //     ans.push_back(curr->val);
    // }
    reverse(ans.begin(),ans.end());

    return ans;
}

vector<int> itreative_postorderV2(TreeNode* root){

    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> s;
    TreeNode*curr = root;
    while(curr || !s.empty()){

        if(curr){
            s.push(curr);
            curr = curr->left;
        }
        else{
            
            TreeNode* tmp = s.top()->right;
            if(tmp==NULL){
                tmp = s.top();
                s.pop();
                ans.push_back(tmp->val);

                while(!s.empty() && tmp == s.top()->right){
                    tmp = s.top();
                    s.pop();
                    ans.push_back(tmp->val);
                }
            }
            else
                curr = tmp;
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

    vector<int> ans = itreative_postorderV2(root);

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
}//4 10 14 8 15 9 5 2 6 13 11 12 7 3 1 