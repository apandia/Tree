#include<iostream>
#include<queue>
#include <vector>
#include <algorithm>

using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

/*Binary Tree Traversal
Input:
      1
    /   \
   2     3
  / \   / \
 4   5 6   7
          / \
         8   9
*/

/** Complexity for all 3(preorder, inorder, postorder) recursive algorithm:
  * TC: O(N)
  * SC: O(N) when tree is skewed otherwise O(H) where H is height of the tree
  * Worst case space complexity (skewed tree) = O(N)
  * Best case space complexity (balanced tree) = O(log N)
 **/

//Preorder Traversal Output: (Root Left Right) 1 2 4 5 3 6 7 8 9
void preorderTraversalHelper(Node *root, vector<int>& arr)
{
    if(root == nullptr)
        return;

    cout<<root->data<<" ";
    arr.push_back(root->data);

    preorderTraversalHelper(root->left, arr);
    preorderTraversalHelper(root->right, arr);
}

vector<int> preorderTraversal(Node *root)
{
    vector<int> preOrder;

    cout << "Preorder: " << endl;
    preorderTraversalHelper(root, preOrder);

    cout<<endl;

    return preOrder;
}

//Inorder Traversal Output: (Left Root Right) 4 2 5 1 6 3 8 7 9
void inorderTraversalHelper(Node *root, vector<int>& arr)
{
    if(root == nullptr)
        return;

    inorderTraversalHelper(root->left, arr);

    cout<<root->data<<" ";
    arr.push_back(root->data);

    inorderTraversalHelper(root->right, arr);
}

vector<int> inorderTraversal(Node *root)
{
    vector<int> inOrder;

    cout << "Inorder: " << endl;
    inorderTraversalHelper(root, inOrder);

    cout<<endl;

    return inOrder;
}

//Postorder Traversal Output: (Left Right Root) 4 5 2 6 8 9 7 3 1
void postorderTraversalHelper(Node *root, vector<int>& arr)
{
    if(root == nullptr)
        return;

    postorderTraversalHelper(root->left, arr);
    postorderTraversalHelper(root->right, arr);

    cout<<root->data<<" ";
    arr.push_back(root->data);
}

vector<int> postorderTraversal(Node *root)
{
    vector<int> postOrder;

    cout << "Postorder: " << endl;
    postorderTraversalHelper(root, postOrder);

    cout<<endl;

    return postOrder;
}

//Driver function
int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);

    vector<int> pre =  preorderTraversal(root);

    cout << "Preorder Traversal: " << endl;
    for (int i = 0; i < pre.size(); i++)
    {
        cout << pre[i] << " ";
    }
    cout<<endl;

    vector<int> in =  inorderTraversal(root);

    cout << "Inorder Traversal: " << endl;
    for (int i = 0; i < in.size(); i++)
    {
        cout << in[i] << " ";
    }
    cout<<endl;

    vector<int> post =  postorderTraversal(root);

    cout << "Postorder Traversal: " << endl;
    for (int i = 0; i < post.size(); i++)
    {
        cout << post[i] << " ";
    }
    cout<<endl;

    return 0;
}
