#include <iostream>
#include <vector>

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

// Construct a BST from preorder traversal
//Input - {8,5,1,7,10,12}
/*
Output:
          8
         / \
        5  10
       / \   \
      1   7   12
Preorder Print - {8,5,1,7,10,12}
*/
//TC: O(3N) ~ O(N) (a node is traveresd 3 times, from parent, left and right)
//SC: O(1) [O(N) is recursive stack space is considered)

Node* buildBST(vector<int>& preorder, int& index, int maxBound)
{
    if(index == preorder.size() || preorder[index] > maxBound)
        return nullptr;

    Node* root = new Node(preorder[index]);
    index++;

    root->left = buildBST(preorder, index, root->data);
    root->right = buildBST(preorder, index, maxBound);

    return root;
}

Node* bstFromPreorder(vector<int>& preorder)
{
    int i =0;
    return buildBST(preorder, i, INT_MAX);
}

void preorderTraversal(Node* root)
{
    if(root == nullptr)
        return;

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//Driver function
int main()
{
    vector<int> preorder={8,5,1,7,10,12};

    Node* root = bstFromPreorder(preorder);

    cout<<"Tree is = ";
    preorderTraversal(root);
    cout<<endl;

    return 0;
}
