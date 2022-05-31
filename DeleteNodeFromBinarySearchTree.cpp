#include <iostream>

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

// Delete node from BST
/*
Input Tree:
          5                        5
        /   \                    /   \
       3     6   --->           2     6
      / \     \                  \     \
     2   4     7                  4     7

Output:
Tree Before deletion (Preorder) - 5 3 2 4 6 7
Tree after deleting 3 (Preorder) - 5 2 4 6 7
*/
Node* findRightMostChild(Node* node)
{
    if(node->right == nullptr)
        return node;

    return findRightMostChild(node->right);
}

Node* deleteNodeHelper(Node* node)
{
    //1. if there is no left node, return right node
    if(node->left == nullptr)
        return node->right;

    //2. if there is no right node, return left node
    if(node->right == nullptr)
        return node->left;

    //3. Find right child
    Node* rightChild = node->right;

    //4. FInd the rightmost child in left subtree
    Node* rightMostChild = findRightMostChild(node->left);

    //5. Make the right child as right child of right most node in left subtree
    rightMostChild->right = rightChild;

    //6. return the left node of the node to be deleted
    return node->left;
}

//TC: O(log N) (Base 2)
//SC: O(N)
Node* deleteNodeFromBST(Node* root, int key)
{
    if(root == nullptr)
        return nullptr;

    if(root->data == key)
        return deleteNodeHelper(root);

    Node* curr = root;

    while(curr)
    {
        if(key < curr->data)
        {
            //Key is on left side
            if(curr->left != nullptr && curr->left->data == key)
            {
                curr->left = deleteNodeHelper(curr->left);
                break;
            }
            else
            {
                curr = curr->left;
            }
        }
        else
        {
            //Key is on right side
            if(curr->right != nullptr && curr->right->data == key)
            {
                curr->right = deleteNodeHelper(curr->right);
                break;
            }
            else
            {
                curr = curr->right;
            }
        }
    }

    return root;
}

void preorderPrint(Node* root)
{
    if(root == nullptr)
        return;

    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

//Driver function
int main()
{
    Node* root = new Node(5);

    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right = new Node(6);
    root->right->right = new Node(7);

    cout<<"Tree before deletion = ";
    preorderPrint(root);
    cout<<endl;

    root = deleteNodeFromBST(root, 3);

    cout<<"Tree after deleting 3 = ";
    preorderPrint(root);
    cout<<endl;

    return 0;
}
