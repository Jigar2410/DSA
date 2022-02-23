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

int cnt = 0;
int kthsmall(TreeNode* root,int k){

    if(!root) return 0;

    int lt = kthsmall(root->left,k);
    if(lt > 0) return lt;

    cnt++;
    if(cnt == k){
        return root->val;
    }

    int rt = kthsmall(root->right,k);
    return rt;

}

int kthsmallItr(TreeNode* root,int k){

    int cnt = 0;
    TreeNode* curr = root;
    stack<TreeNode*> st;
    while(1){

        if(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{

            if(st.empty()) break;

            cnt++;
            
            curr = st.top();
            st.pop();
            if(cnt==k) return curr->val;

            curr = curr->right;
        }
    }

    return 0;
}

int kthsmall(TreeNode* root,int k){

    int cnt = 0,ans = 0;
    TreeNode* curr = root;
    while(curr){
        if(curr->left == NULL){
            cnt++;
            if(cnt==k) ans = curr->val;
            curr = curr->right;
        }
        else{
            TreeNode* prev = curr->left;
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }
            else{

                cnt++;
                if(cnt == k) ans = curr->val;
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main(){

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(12);
    root->right->right->left = new TreeNode(11);
    root->right->right->right = new TreeNode(14);


    /*
                    
                   8
                  / \ 
                 6   9
                /  \  \       
               4    7  12  
              /        / \
             1        11  14                           
 
    */
    return 0;
}