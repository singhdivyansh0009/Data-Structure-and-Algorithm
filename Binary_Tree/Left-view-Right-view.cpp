#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class TreeNode{
   public :
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
      data = val;
      left = NULL;
      right = NULL;
    }
};
vector<int> printLeftView(TreeNode* root) {
    vector<int>ans;
    queue<TreeNode*>q;
    q.push(root);
    int position;
    while(!q.empty()){
        position = 1;
        q.push(NULL);
        while(true){
            TreeNode* curNode = q.front();
            q.pop();
            if(!curNode)
               break;
            if(position==1)
               ans.push_back(curNode->data);
            if(curNode->left)
              q.push(curNode->left);
            if(curNode->right)
              q.push(curNode->right);
            position++;
        }
    }
    return ans;
}
vector<int> printRightView(TreeNode* root) {
    vector<int>ans;
    queue<TreeNode*>q;
    q.push(root);
    int levelSize;
    while(!q.empty()){
        levelSize = q.size();  // total no. nodes in current level
        while(levelSize){
            TreeNode* curNode = q.front();
            q.pop();
            if(levelSize==1)
               ans.push_back(curNode->data);  // pushing the last element of every level
            if(curNode->left)
              q.push(curNode->left);
            if(curNode->right)
              q.push(curNode->right);
            levelSize--;
        }
    }
    return ans;
}
int main(){
   TreeNode* root = NULL;
   root->data = new TreeNode (5);
   root->left->data = new TreeNode (10);
   root->right->data = new TreeNode (20);
   root->left->left->data = new TreeNode (30);
   root->left->right->data = new TreeNode (40);
   root->right->left->data = new TreeNode (50);
   root->right->right->data = new TreeNode (60);
   vector<int>ans;
   ans = printLeftView(root);
   for(auto i : ans)
      cout << i << " ";
}
/*
       5
     /   \
   10     20
  /  \   /  \
30   40 50   60

*/
