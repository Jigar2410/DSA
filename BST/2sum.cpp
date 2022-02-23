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

class BSTIterator{
public:
    stack<TreeNode*> st;
    bool reverse;
    // reverse->true = before()
    // reverse->false = next()
    
    BSTIterator(TreeNode* root,bool isreverse){
        reverse = isreverse;
        pushAll(root);
    }

    bool hasNext(){
        return (!st.empty());
    }
    
    int next(){
        
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }
    
private:    
    void pushAll(TreeNode* root){
        for(;root!=NULL;){
            st.push(root);
            if(!reverse) root = root->left;
            else root = root->right;
        }
    }
    
};

bool findTarget(TreeNode* root, int k) {
    
    if(!root) return false;
    
    BSTIterator l(root,false);
    BSTIterator r(root,true);
    
    int i = l.next();
    int j = r.next();
    
    while(i<j){
        if(i+j == k) return true;
        else if(i+j < k) i = l.next();
        else j = r.next();
    }
    
    return false;
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

    successor(root,9);
    cout<<succ<<endl;
    predecessor(root,9);
    cout<<pred<<endl;
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