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

void preorder(TreeNode* root){
    
    if(!root) return;
    
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

 void serialUtil(TreeNode* root,string &s){
        
    if(root==NULL) {
        s+="# ";
        return;
    }
    
    s += to_string(root->val) + " ";
    
    serialUtil(root->left,s);
    serialUtil(root->right,s);
}

string serialize(TreeNode* root) {
    
    string s="";
    serialUtil(root,s);
    return s;
    
}

TreeNode* deserialUtil(stringstream &s){
  
    string x;
    s>>x;
    if(x=="#") return NULL;
    
    TreeNode* root = new TreeNode(stoi(x));
    root->left = deserialUtil(s);
    root->right = deserialUtil(s);
    
    return root;
}
// Decodes your encoded data to tree.

TreeNode* deserialize(string data) {
    
    stringstream s(data);
    return deserialUtil(s);
}

string serializ14(TreeNode* root) {
        
    string s = "";
    if(!root) return "# ";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        
        int size = q.size();
        for(int i=0;i<size;i++){
            
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr==NULL){
                s += "# ";
            }
            else{
                
                s += to_string(curr->val)+" ";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
    }

    return s;
}

// Decodes your encoded data to tree.
TreeNode* deserialize1(string data) {
    
    stringstream s(data);
    string x;
    s >> x;
    if(x=="#") return NULL;
    queue<TreeNode*> q;
    TreeNode*root = new TreeNode(stoi(x));
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode*curr = q.front();
            q.pop();
         
            s>>x;
            if(x!="#"){
                curr->left = new TreeNode(stoi(x));
                q.push(curr->left);
            }

            s>>x;
            if(x!="#"){
                curr->right = new TreeNode(stoi(x));
                q.push(curr->right);
            }
        }
    }
    return root;
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


    string s = serialize(root);
    cout<<s<<endl;

    TreeNode* root1 = deserialize(s);
    preorder(root1);
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