#include<iostream>

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

/*Check Identical Binary Tree
Input Tree1:                Input Tree2:
        1                           1
       / \                         / \
      2   3                       2   3
       \   \                       \   \
        4   5                       4   5
       /                           /
      6                           6
*/

//Recursive Approach :
//TC - O(N)
//SC - O(H), O(N) for skewed tree
bool checkIdenticalTree(Node* tree1, Node* tree2)
{
    if((tree1 == nullptr) || (tree2 == nullptr))
        return (tree1 == tree2);

    return ((tree1->data == tree2->data)
            && checkIdenticalTree(tree1->left, tree2->left)
            && checkIdenticalTree(tree1->right, tree2->right));
}

//Driver function
int main()
{
    Node* tree1 = new Node(1);

    tree1->left = new Node(2);
    tree1->left->right = new Node(4);
    tree1->left->right->left = new Node(6);

    tree1->right = new Node(3);
    tree1->right->right = new Node(5);

    Node* tree2 = new Node(1);

    tree2->left = new Node(2);
    tree2->left->right = new Node(4);
    tree2->left->right->left = new Node(6);

    tree2->right = new Node(3);
    tree2->right->right = new Node(5);

    if(checkIdenticalTree(tree1,tree2))
        cout<<"Both trees are identical"<<endl;
    else
        cout<<"Both trees are not identical"<<endl;

    return 0;
}
