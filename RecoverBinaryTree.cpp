#include <iostream>
#include <stack>

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

// Find Inorder Successor and Predecessor of a node in BST
/*
Input Tree:
                    3                  2
                   / \                / \
                  1   4  --->        1   4
                     /                  /
                    2                  3

*/

//TC:
//SC:

class Solution{
public:
    void recoverBST(Node* root)
    {
        prev = first = middle = last = nullptr;

        inorder(root);

        if(first != nullptr && last != nullptr)
            swap(first->data, last->data);
        else if(first != nullptr && middle != nullptr)
            swap(first->data, middle->data);
    }

private:
    void inorder(Node* root)
    {
        if(root == nullptr)
            return;

        inorder(root->left);

        if(prev != nullptr && root->data < prev->data)
        {
            if(first == nullptr){
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }

        prev = root;
        inorder(root->right);
    }

private:
    Node* prev;
    Node* first;
    Node* middle;
    Node* last;
};

void inorderTraversal(Node* root)
{
    if(root == nullptr)
        return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

//Driver function
int main()
{
    Node* root = new Node(3);

    root->left = new Node(1);

    root->right = new Node(4);
    root->right->left = new Node(2);

    cout<<"Inorder Traversal before recovery of tree = ";
    inorderTraversal(root);
    cout<<endl;

    Solution obj;
    obj.recoverBST(root);

    cout<<"Inorder Traversal after recovery of tree = ";
    inorderTraversal(root);
    cout<<endl;

    return 0;
}
