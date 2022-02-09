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

// There will be no such case where at same level and same vertical 2 or more nodes come 
void topView(TreeNode* root,int vertical,int level,map<int,pair<int,int>> &mp){

    if(!root) return;

    if(!mp.count(vertical) || mp[vertical].first > level){
        mp[vertical] = {level,root->val};
    }

    topView(root->left,vertical-1,level+1,mp);
    topView(root->right,vertical+1,level+1,mp);   
}


// If 2 or more nodes at same vertical and same level then include one which more towards right
void bottomView(TreeNode* root,int vertical,int level,map<int,pair<int,int>> &mp){

    if(!root) return;

    if(!mp.count(vertical) || mp[vertical].first <= level){
        mp[vertical] = {level,root->val};
    }

    bottomView(root->left,vertical-1,level+1,mp);
    bottomView(root->right,vertical+1,level+1,mp);   
}

void leftView(TreeNode* root,int& max_level,int level,vector<int>&ans){

    if(!root) return;

    if(max_level < level){
        ans.push_back(root->val);
        max_level = level;
    }

    leftView(root->left,max_level,level+1,ans);
    leftView(root->right,max_level,level+1,ans);   
}

void rightView(TreeNode* root,int& max_level,int level,vector<int>&ans){

    if(!root) return;

    if(max_level < level){
        ans.push_back(root->val);
        max_level = level;
    }

    rightView(root->right,max_level,level+1,ans);
    rightView(root->left,max_level,level+1,ans);   
}

vector<int> topViewItr(TreeNode* root){

    vector<int> ans;
    if(!root) return ans;
    map<int,int> mp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr = q.front().first;
            int vertical = q.front().second;    
            q.pop();

            // just insert at first time 
            if(!mp.count(vertical)) mp[vertical] = curr->val;

            if(curr->left) q.push({curr->left,vertical-1});
            if(curr->right) q.push({curr->right,vertical+1});
        }
    }
    for(auto x : mp){
        ans.push_back(x.second);
    }
      return ans;
}

vector<int> bottomViewItr(TreeNode* root){

    vector<int> ans;
    if(!root) return ans;
    map<int,int> mp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr = q.front().first;
            int vertical = q.front().second;    
            q.pop();

            // keep on updating 
            mp[vertical] = curr->val;

            if(curr->left) q.push({curr->left,vertical-1});
            if(curr->right) q.push({curr->right,vertical+1});
        }
    }
    for(auto x : mp){
        ans.push_back(x.second);
    }

    return ans;
}

vector<int> leftViewItr(TreeNode* root){

    vector<int> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){

        int size = q.size();
        int level = -1;
        for(int i=0;i<size;i++){
            TreeNode* curr = q.front();
            q.pop();

            if(level==-1){
                level = curr->val;
            }

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        ans.push_back(level);
    }
    return ans;
}

vector<int> rightViewItr(TreeNode* root){

    vector<int> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){

        int size = q.size();
        int level = -1;
        for(int i=0;i<size;i++){
            TreeNode* curr = q.front();
            q.pop();

            level = curr->val;
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        ans.push_back(level);
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

    map<int,pair<int,int>> mp;
    topView(root,0,0,mp);
    for(auto x:mp){
        cout<<x.second.second<<" ";
    }

    cout<<endl<<endl; 

    map<int,pair<int,int>> mp1;
    bottomView(root,0,0,mp1);
    for(auto x:mp1){
        cout<<x.second.second<<" ";
    }

    cout<<endl<<endl; 

    vector<int> ans;
    int max_level=0;
    leftView(root,max_level,1,ans);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";

    cout<<endl<<endl;

    
    vector<int> ans1;
    max_level=0;
    rightView(root,max_level,1,ans1);
    for(int i=0;i<ans1.size();i++) cout<<ans1[i]<<" ";

    cout<<endl<<endl;

    vector<int> v = topViewItr(root);
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";

    cout<<endl<<endl;

    vector<int> v1 = bottomViewItr(root);   
    for(int i=0;i<v1.size();i++) cout<<v1[i]<<" ";

    cout<<endl<<endl;

    vector<int> v2 = leftViewItr(root);   
    for(int i=0;i<v2.size();i++) cout<<v2[i]<<" ";

    cout<<endl<<endl;
        
    vector<int> v3 = rightViewItr(root);   
    for(int i=0;i<v3.size();i++) cout<<v3[i]<<" "; 
    
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