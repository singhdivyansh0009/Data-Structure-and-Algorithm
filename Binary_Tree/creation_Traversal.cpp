#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node *buildTree(Node *root)
{
    int data;
    cout << "enter the data";
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;
    cout << "enter the left data of " << data << "\n";
    root->left = buildTree(root->left);
    cout << "enter the right data of " << data << "\n";
    root->right = buildTree(root->right);
    return root;
}
int levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curNode = q.front();
        cout << curNode->data << " ";
        q.pop();
        if (curNode->left)
            q.push(curNode->left);
        if (curNode->right)
            q.push(curNode->right);
    }
    return 1;
}
int PreOrderTraversal(Node *root)
{
    if (!root)
        return 0;
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}
int PostOrderTraversal(Node *root)
{
    if (!root)
        return 0;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data;
}
int InOrderTraversal(Node *root)
{
    if (!root)
        return 0;
    PostOrderTraversal(root->left);
    cout << root->data;
    PostOrderTraversal(root->right);
}
int heightOfTree(Node *root)
{
    if (!root)
        return 0;
    int lh = heightOfTree(root->left) + 1;
    int rh = heightOfTree(root->right) + 1;
    return max(lh, rh);
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    PreOrderTraversal(root);
    PostOrderTraversal(root);
    cout << heightOfTree(root);
}
/*
      1
     /  \
    2    3
   / \  / \
  5   6 8   4
*/
