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

//Lowest common ancestor
/*
Input Tree:
         1
        / \
       2   3
          / \
         4   5
        / \
       6   7
          /
         8

Lowest common ancestor between 8 and 5 = 3
Lowest common ancestor between 8 and 2 = 1
Lowest common ancestor between 8 and 4 = 4
*/

//TC: O(N)
//SC: O(H) (O(N) for skewed tree)
Node* lowestCommonAncestorForNodes(Node* root, Node* p, Node* q)
{
    if((root == nullptr) || (root == p) || (root == q))
        return root;

    Node* left = lowestCommonAncestorForNodes(root->left, p, q);
    Node* right = lowestCommonAncestorForNodes(root->right, p, q);

    if(left == nullptr){
        return right;
    }
    else if(right == nullptr){
        return left;
    }
    else {
        return root;
    }
}

Node* lowestCommonAncestorForValues(Node* root, int p, int q)
{
    if((root == nullptr) || (root->data == p) || (root->data == q))
        return root;

    Node* left = lowestCommonAncestorForValues(root->left, p, q);
    Node* right = lowestCommonAncestorForValues(root->right, p, q);

    if(left == nullptr){
        return right;
    }
    else if(right == nullptr){
        return left;
    }
    else {
        return root;
    }
}

//Driver function
int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);

    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);

    root->right->left->right->left = new Node(8);

    cout<<"Lowest common ancestor using node pointer"<<endl;
    cout<<"Lowest common ancestor between 8 and 5 = ";
    Node* lca = lowestCommonAncestorForNodes(root, root->right->left->right->left, root->right->right);

    if(lca != nullptr)
        cout<<lca->data<<endl;
    else
        cout<<"There is no common ancestor"<<endl;


    cout<<"Lowest common ancestor between 8 and 2 = ";
    lca = lowestCommonAncestorForNodes(root, root->right->left->right->left, root->left);

    if(lca != nullptr)
        cout<<lca->data<<endl;
    else
        cout<<"There is no common ancestor"<<endl;

    cout<<"Lowest common ancestor between 8 and 4 = ";
    lca = lowestCommonAncestorForNodes(root, root->right->left->right->left, root->right->left);

    if(lca != nullptr)
        cout<<lca->data<<endl;
    else
        cout<<"There is no common ancestor"<<endl;

    cout<<endl;
    cout<<"Lowest common ancestor using node value"<<endl;
    cout<<"Lowest common ancestor between 8 and 5 = ";
    lca = lowestCommonAncestorForValues(root, 8, 5);

    if(lca != nullptr)
        cout<<lca->data<<endl;
    else
        cout<<"There is no common ancestor"<<endl;

    cout<<"Lowest common ancestor between 8 and 2 = ";
    lca = lowestCommonAncestorForValues(root, 8, 2);

    if(lca != nullptr)
        cout<<lca->data<<endl;
    else
        cout<<"There is no common ancestor"<<endl;

    cout<<"Lowest common ancestor between 8 and 4 = ";
    lca = lowestCommonAncestorForValues(root, 8, 4);

    if(lca != nullptr)
        cout<<lca->data<<endl;
    else
        cout<<"There is no common ancestor"<<endl;

    return 0;
}
