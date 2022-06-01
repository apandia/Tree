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

// Find Inorder Successor and Predecessor of a node in BST
/*
Input Tree:
                     5
                   /   \
                  3     7
                 / \   /  \
                2   4 6    9
               /          / \
              1          8   10


Inorder Successor[8] = 9
There is no inorder successor[10]
Inorder Successor[1] = 2
Inorder Predecessor[8] = 7
There is no inorder Predecessor[1]
*/
//TC: O(H)
//SC: O(1) [O(N) is recursive stack space is considered)

Node* inorderSuccessor(Node* root, Node* node)
{
    Node* is = nullptr;

    Node* curr = root;
    while(curr)
    {
        if(node->data >= curr->data)
        {
            curr = curr->right;
        }
        else
        {
            is = curr;
            curr = curr->left;
        }
    }
    return is;
}

Node* inorderPredecessor(Node* root, Node* node)
{
    Node* ip = nullptr;

    Node* curr = root;
    while(curr)
    {
        if(node->data <= curr->data)
        {
            curr = curr->left;
        }
        else
        {
            ip = curr;
            curr = curr->right;
        }
    }
    return ip;
}

//Driver function
int main()
{
    Node* root = new Node(5);

    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);

    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(9);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(10);

    Node* successor = inorderSuccessor(root, root->right->right->left);
    if(successor != nullptr)
        cout<<"Inorder Successor[8] = "<<successor->data<<endl;
    else
        cout<<"There is no inorder successor[8]"<<endl;

    successor = inorderSuccessor(root, root->right->right->right);
    if(successor != nullptr)
        cout<<"Inorder Successor[10] = "<<successor->data<<endl;
    else
        cout<<"There is no inorder successor[10]"<<endl;

    successor = inorderSuccessor(root, root->left->left->left);
    if(successor != nullptr)
        cout<<"Inorder Successor[1] = "<<successor->data<<endl;
    else
        cout<<"There is no inorder successor[1]"<<endl;

    Node* predecessor = inorderPredecessor(root, root->right->right->left);
    if(successor != nullptr)
        cout<<"Inorder Predecessor[8] = "<<predecessor->data<<endl;
    else
        cout<<"There is no inorder Predecessor[8]"<<endl;

    predecessor = inorderPredecessor(root, root->left->left->left);
    if(predecessor != nullptr)
        cout<<"Inorder Predecessor[1] = "<<predecessor->data<<endl;
    else
        cout<<"There is no inorder Predecessor[1]"<<endl;

    return 0;
}
